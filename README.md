Introduction
============

PandaTree contains the panda data format and the tools to create and extend the C++ library for the format. The written format is fully flat (simple C types and arrays only) and is as "dumb" as it gets, which means that it is slim, fast to read/write, and fully portable (no library is needed read the files). The library defines the interface which constructs C++ objects from this flat tree so that the analyis programs don't have to be dumb.

Quickstart
==========

Compile
-------
Just run scram b.

Read
----
```cpp
#include "PandaTree/Objects/interface/Event.h"

TTree* eventsTree(static_cast<TTree*>(file->Get("events")));

panda::Event event;
event.setAddress(*eventsTree);

long iEntry(0);
while (event.getEntry(*eventsTree, iEntry++) > 0) { // IMPORTANT: *not* eventsTree->GetEntry()
  /* do your analysis */
}
```

Write
-----
```cpp
#include "PandaTree/Objects/interface/Event.h"

TTree* eventsTree(new TTree("events", "Events"));
TTree* runsTree(new TTree("runs", "Runs"));

panda::Event event;
event.book(*eventsTree);
event.run.book(*runsTree);

for (unsigned iEntry(0); iEntry != maxEntries; ++iEntry) {
  /* fill your event */

  event.fill(*eventsTree);

  if (is_new_run) {
    /* fill your run */
    event.run.fill(*runsTree);
  }
}
```

Objects and files structure
===========================

Physics objects all have pt(), eta(), phi(), and m() functions. Other available variables and functions are listed in the format definition file panda.def (syntax documented below). Objects have inheritance relations, so e.g. an Electron object has all the variables of Lepton, ParticleP, and Particle objects.

The actual C++ code defining the objects are all in the Objects subdirectory. This entire subdirectory is generated automatically from the format definition file.

Objects are often stored in variable-size containers ("Collection"s), which have similar interfaces to std::vector. Code for Collection and other general-use objects are in the Framework subdirectory.

Technical details
=================

Tree structures are defined in tree definition files and then converted to C++ code by `generate.py`. Usage is
```
generate.py [definition files]
```
If no definition files are specified, all files in the defs/ directory will be read. The definition files must have names ending with ".def", and two files cannot share the same name even if they exist in different directories. The script will write C++ source code into Objects/ and obj/ directories.

Tree definition file is made of various sections and blocks. A comment line starts with a '%' character. All typedefs, enums, constants, and classes will be defined under a namespace specified in `lib/panda/common.py`.

1. Requirements

   If a definition file makes reference to objects defined in other definition files, the file must start with a block for each requirement line in the format <require [def name]>.

1. Includes

   Define all headers to be included in the object definition headers.

1. Typedefs

   Similarly, define all typedefs.

1. Constants

   Constants defined in this section can be used in the object definitions.

1. Asserts

   Assertions to be made at compile-time. This can be used to assure that the constants satisfy certain conditions.

1. Enums

   C++ enums. An entry of name n{NAME}s will be automatically appended, where {NAME} is the name of the enum.

1. Objects

   This section is the core of the definition file. Each object definition is started with a line  
`[Obj(>Parent)(<Mixins)(:SINGLE)]`
where Obj is the name of the class, Parent is its base class, Mixins is a comma-separated list of "mixin" parent classes to add specific features, and SINGLE indicates that the object is not meant to be placed in container classes (Array and Collection).

   Everything that follows after the object name until the next blank line is parsed as the definition of the object. Within this block, object variables (i.e. ROOT branches), references (pointers to other objects), constants, and functions can be defined. Variables are defined by syntax
`name([array_spec])/type`
where array_spec can be multi-dimensional and can use either integer literals or the constants defined in the constants section.

   Branch types follow the ROOT convention:
O -> Bool_t (capital o)
b -> UChar_t
B -> Chart_t
s -> UShort_t
S -> Short_t
i -> UInt_t
I -> Int_t
l -> ULong64_t
L -> Long64_t
F -> Float_t
D -> Double_t
C -> Chart_t*

   References are defined by syntax
`name/classRef (single reference)`
and
`name/classRefVector (vector of references)`

   In the ROOT file, the references are represented by integers which correspond to the index of the object that is pointed to within its owning collection. Thus one has to specify element of which collection this reference points to, and this is done in the Tree definition (see below).

1. Mixins

   Mixins specification syntax is similar to Objects. There can be branches and functions defined for a Mixin. Branches will become data members of the Mixin class, while the functions are directly added to Object classes that use the Mixin.

8. Trees

   Tree names are specified by {Name}. Everything that follows a tree declaration until the next blank
line is considered as tree definition.

   Syntax for specifying simple variables of the tree object is identical to the one for physics objects. In addition, various arrays, collections, and singlets can be attached to the tree. If an attached physics object contains a reference that points to elements in another container, use the '->' symbol to represent referencing:
photons/PhotonCollection
superClusters/SuperClusterCollection
photons.superCluster->superClusters

Tree input/output
=================

Each object variable is booked an independent TBranch. The objects know how to write out and read in
the branch values from TTree. Collections use variable names in the tree definition to book branches.
For example, consider a file particles.def with the following content:
```
[ParticleP]
pt_/F
eta_/F
phi_/F

{Event}
myparts/ParticlePCollection
```

Running
`enerate.py particles.def`
will result in the following TTree structure:
```
tree (name not fixed)
 L myparts.size/i
 L myparts.pt_[myparts.size]/F
 L myparts.eta_[myparts.size]/F
 L myparts.phi_[myparts.size]/F
```

Speeding up I/O
===============

It is possible to specify which branches to read and write.
By limiting I/O to only the branches you actually use, it is possible to significantly speed up
the analysis program.
```cpp
event.setAddress(*tree, {"!*", "electrons.pt_", "electrons.eta_"});
```

The second argument of setAddress is an ordered list of "commands" to turn branches on and off.
For each branch in the tree, the last matching command takes effect. Thus in the example above,
all branches in the tree are disabled (by the "!" sign) but electrons.pt_ and electrons.eta_ are
re-enabled.
