#include "circuit.h"
#include "GateAND.h"
#include "GateOR.h"
#include "GateNOT.h"

int main() {
    circuit Circ;
    Circ.gates.push_back(new GateAND(Node("I1"), Node("I2"), Node("A")));
    Circ.gates.push_back(new GateOR(Node("I3"), Node("I4"), Node("B")));
    Circ.gates.push_back(new GateAND(Node("B"), Node("I5"), Node("C")));
    Circ.gates.push_back(new GateOR(Node("A"), Node("C"), Node("O1")));
    Circ.gates.push_back(new GateOR(Node("C"), Node("I6"), Node("O3")));
    Circ.gates.push_back(new GateNOT(Node("C"), Node("O2")));

    Circ.inputs.push_back(Node("I1", false));
    Circ.inputs.push_back(Node("I2", true));
    Circ.inputs.push_back(Node("I3", false));
    Circ.inputs.push_back(Node("I4", false));
    Circ.inputs.push_back(Node("I5", true));
    Circ.inputs.push_back(Node("I6", true));

    Circ.outputs.push_back(Node("O1"));
    Circ.outputs.push_back(Node("O2"));
    Circ.outputs.push_back(Node("O3"));

    Circ.compute();
    Circ.show_gates();

    return 0;
}