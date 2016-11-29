#!/usr/bin/env python

import sys
import os
from argparse import ArgumentParser
sys.path.append(os.path.dirname(os.path.realpath(__file__)) + '/lib')
from panda import *

argParser = ArgumentParser(description = 'Generate C++ code for a flat tree')
argParser.add_argument('configs', metavar = 'CONFIG', nargs = '+', help = 'Tree definition files.')
argParser.add_argument('--clear-custom', '-C', dest = 'clear_custom', action = 'store_true', help = 'Clear custom code.')

args = argParser.parse_args()

if args.clear_custom:
    common.PRESERVE_CUSTOM = False

# globals
includes = [
    Include('#include "TTree.h"'),
    Include('#include "TString.h"'),
    Include('#include "Rtypes.h"')
]
typedefs = []
constants = []
asserts = []
enums = []
functions = []
phobjects = []
trees = []

# parse all config files
for fname in args.configs:
    configFile = open(fname)

    while True:
        line = configFile.readline()
        if line == '':
            break

        line = line.strip()
        
        if line == '':
            continue

        if line.startswith('%'):
            #comment line
            continue

        try:
            includes.append(Include(line))
            continue
        except Definition.NoMatch:
            pass

        try:
            typedefs.append(Typedef(line))
            continue
        except Definition.NoMatch:
            pass

        try:
            constants.append(Constant(line))
            continue
        except Definition.NoMatch:
            pass

        try:
            asserts.append(Assert(line))
            continue
        except Definition.NoMatch:
            pass

        try:
            enums.append(Enum(line, configFile))
            continue
        except Definition.NoMatch:
            pass

        try:
            functions.append(Function(line, configFile))
            continue
        except Definition.NoMatch:
            pass

        try:
            phobjects.append(PhysicsObject(line, configFile))
            continue
        except Definition.NoMatch:
            pass

        try:
            trees.append(Tree(line, configFile))
            continue
        except Definition.NoMatch:
            pass

        print 'Skipping unrecognized pattern:', line

    configFile.close()

# create directories if necessary
if not os.path.isdir(common.PACKDIR + '/Objects/interface'):
    os.makedirs(common.PACKDIR + '/Objects/interface')
if not os.path.isdir(common.PACKDIR + '/Objects/src'):
    os.makedirs(common.PACKDIR + '/Objects/src')
if not os.path.isdir(common.PACKDIR + '/obj'):
    os.makedirs(common.PACKDIR + '/obj')

# are we running in a CMSSW environment?
if os.path.exists(common.PACKDIR + '/../../.SCRAM/Environment'):
    with open(common.PACKDIR + '/../../.SCRAM/Environment') as environment:
        if 'CMSSW' in environment.readline():
            # if so, we need to write the build file
            with open(common.PACKDIR + '/Objects/BuildFile.xml', 'w') as buildFile:
                buildFile.write('<use name="root"/>\n')
                buildFile.write('<use name="{PACKAGE}/Framework"/>\n'.format(PACKAGE = common.PACKAGE))
                buildFile.write('<export>\n')
                buildFile.write('  <lib name="1"/>\n')
                buildFile.write('</export>\n')

# write the globals file
header = FileOutput(common.PACKDIR + '/Objects/interface/Constants.h')
header.writeline('#ifndef {PACKAGE}_Objects_Constants_h'.format(PACKAGE = common.PACKAGE))
header.writeline('#define {PACKAGE}_Objects_Constants_h'.format(PACKAGE = common.PACKAGE))
header.newline()

for include in includes:
    include.write(header)

header.writeline('#include <cstring>')

header.newline()
header.writeline('namespace {NAMESPACE} {{'.format(NAMESPACE = common.NAMESPACE))
header.newline()
header.indent += 1

if len(typedefs) != 0:
    for typedef in typedefs:
        typedef.write(header)

    header.newline()

for enum in enums:
    enum.write_decl(header)
    header.newline()

if len(constants) != 0:
    for constant in constants:
        constant.write_decl(header, context = 'global')

    header.newline()

Assert.write(asserts, header)

for function in functions:
    function.write_decl(header, context = 'global')
    header.newline()

if len(header.custom_blocks) != 0:
    header.write(header.custom_blocks[0])
else:
    header.writeline('/* BEGIN CUSTOM */')
    header.writeline('/* END CUSTOM */')
header.newline()

header.indent -= 1
header.writeline('}')

header.newline()

header.writeline('#endif')
header.close()

# .cc for constants
src = FileOutput(common.PACKDIR + '/Objects/src/Constants.cc')
src.writeline('#include "../interface/Constants.h"')

for enum in enums:
    src.newline()
    enum.write_def(src)

for function in functions:
    src.newline()
    function.write_def(src, context = 'global')

src.newline()
if len(src.custom_blocks) != 0:
    src.write(src.custom_blocks[0])
else:
    src.writeline('/* BEGIN CUSTOM */')
    src.writeline('/* END CUSTOM */')

src.close()

# write code for all objects and trees
for objdef in phobjects + trees:
    objdef.generate_header()
    objdef.generate_source()

# write a linkdef file (not compiled by CMSSW - only for Makefile)
linkdef = FileOutput(common.PACKDIR + '/obj/LinkDef.h')
linkdef.writeline('#include "../Framework/interface/Object.h"')
linkdef.writeline('#include "../Framework/interface/Container.h"')
for objdef in phobjects:
    linkdef.writeline('#include "../Objects/interface/{name}.h"'.format(name = objdef.name))
for tree in trees:
    linkdef.writeline('#include "../Objects/interface/{name}.h"'.format(name = tree.name))

linkdef.newline()

linkdef.writeline('#ifdef __CLING__')
linkdef.writeline('#pragma link off all globals;')
linkdef.writeline('#pragma link off all classes;')
linkdef.writeline('#pragma link off all functions;')

linkdef.writeline('#pragma link C++ nestedclass;')
linkdef.writeline('#pragma link C++ nestedtypedef;')
linkdef.writeline('#pragma link C++ namespace {NAMESPACE};'.format(NAMESPACE = common.NAMESPACE))

linkdef.newline()

for enum in enums:
    linkdef.writeline('#pragma link C++ enum {NAMESPACE}::{name};'.format(NAMESPACE = common.NAMESPACE, name = enum.name))

for objdef in phobjects:
    linkdef.writeline('#pragma link C++ class {NAMESPACE}::{name};'.format(NAMESPACE = common.NAMESPACE, name = objdef.name))

for objdef in phobjects:
    if objdef.coltype() == PhysicsObject.DYNAMIC:
        conttype = 'Collection'
    elif objdef.coltype() == PhysicsObject.FIXED:
        conttype = 'Array'
    else:
        continue

    if objdef.parent == 'ContainerElement':
        parent = conttype
    else:
        parent = objdef.parent + conttype

    linkdef.writeline('#pragma link C++ class Container<{NAMESPACE}::{name}, {NAMESPACE}::{parent}>;'.format(NAMESPACE = common.NAMESPACE, name = objdef.name, parent = parent))
    linkdef.writeline('#pragma link C++ typedef {NAMESPACE}::{name}{type};'.format(NAMESPACE = common.NAMESPACE, name = objdef.name, type = conttype))

for tree in trees:
    linkdef.writeline('#pragma link C++ class {NAMESPACE}::{name};'.format(NAMESPACE = common.NAMESPACE, name = tree.name))

linkdef.newline()

linkdef.writeline('#endif')
