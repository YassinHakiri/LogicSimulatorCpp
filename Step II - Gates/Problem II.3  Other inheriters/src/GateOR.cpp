/*
 * GateOR.cpp
 *
 *  Created on: 14 déc. 2024
 *      Author: lenovo
 */
#include "GateOR.h"

// Constructeur
GateOR::GateOR(const Node& input1, const Node& input2, const Node& out)
    : Gate("OR", {input1, input2}) {
    output = out;
}

// Méthode pour calculer la sortie (opération OR)
int GateOR::calc_output() {
    if (inputs.size() < 2) {
        return -1;
    }
    for (const auto& input : inputs) {
        if (!input.already_computed) {
            return -1;
        }
    }
    bool result = inputs[0].value;
    for (size_t i = 1; i < inputs.size(); ++i) {
        result = result || inputs[i].value;
    }
    output.set_value(result);
    return 0;
}



