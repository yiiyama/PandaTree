from branch import Branch
from physics import PhysicsObject
from output import FileOutput

def plot_set(objdef):
    to_plot = []

    acceptable = ['bool', 'char', 'int', 'float', 'double',
                  'Bool_t', 'Char_t', 'UChar_t',
                  'UShort_t', 'Short_t', 'UInt_t', 'Int_t',
                  'Long64_t', 'ULong64_t', 'Float_t', 'Double_t']

    to_plot += [b.name for b in objdef.branches \
                    if 'packed' not in b.name and \
                    not b.name.endswith('_') and \
                    not b.is_array() and \
                    Branch.TYPE_MAP.get(b.type, b.type) in acceptable]

    to_plot += [f.signature.split()[0] for f in objdef.functions \
                    if '() const' in f.signature and \
                    f.type in acceptable]

    if objdef.parent not in ['Element', 'Singlet']:
        to_plot += plot_set(PhysicsObject.get(objdef.parent))

    return set(to_plot)

header = """#ifndef IWILLSEEYOULATER
#define IWILLSEEYOULATER 1

#include <vector>
#include "PandaTree/Objects/interface/Event.h"


template <int P>
struct plotter {
  constexpr static const char* name = nullptr;
};
"""

template = """
template <>
struct plotter <%i> {
  constexpr static const char* name = "%s/%s";
  std::vector<float> operator () (panda::Event& event) {
%s
    return output;
  }
};
"""

footer = """
#endif"""


def write_header(trees, file_name):
    writer = FileOutput(file_name)

    num_plots = 0

    writer.writeline(header)

    parsed_objs = set()

    for tree in trees:
        if tree.name not in ['Event', 'EventBase']:
            continue
        for obj in tree.objbranches:
            if obj.name in parsed_objs:
                continue

            parsed_objs.add(obj.name)
            base_dir = obj.name

            set_to_plot = plot_set(PhysicsObject.get(obj.objname))

            for plot in set_to_plot:
                if obj.conttype == 'Collection':
                    action = """
    std::vector<float> output;
    for (auto& i : event.%s)
      output.push_back(i.%s);
""" % (obj.name, plot)
                else:
                    action = '    std::vector<float> output {float(event.%s.%s)};' % (obj.name, plot)

                writer.writeline(template % (num_plots, obj.name, plot.rstrip('()'), action))
                num_plots += 1

    writer.writeline('#define NUM_PLOTS %i' % num_plots)
    writer.writeline(footer)
