#include "GateNOT.h"

// Constructeur
GateNOT::GateNOT(const Node& input, const Node& out)
    : Gate("NOT", {input}) {
    output = out;
}

// Méthode pour calculer la sortie (opération NOT)
int GateNOT::calc_output() {
    if (inputs.size() < 1) {
        return -1;
    }
    if (!inputs[0].already_computed) {
        return -1;
    }
    bool result = !inputs[0].value;
    output.set_value(result);
    return 0;
}