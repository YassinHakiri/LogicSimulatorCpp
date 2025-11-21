//============================================================================
// Name        : 3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "node.h"
#include "Gate.h"
#include "GateAND.h"
#include "GateOR.h"
#include "GateNOT.h"

#include <iostream>
#include <string>
using namespace std ;




int main() {
    // Table de vérité pour la porte AND
    vector<pair<bool, bool>> truth_table = {
        {false, false},
        {false, true},
        {true, false},
        {true, true}
    };

    cout << "Truth table for AND gate:" << endl;
    for (const auto& inputs : truth_table) {
        GateAND gate(Node("I1", inputs.first), Node("I2", inputs.second), Node("O"));
        gate.calc_output();
        gate.show();
    }

    cout << "\nTruth table for OR gate:" << endl;
    for (const auto& inputs : truth_table) {
        GateOR gate(Node("I1", inputs.first), Node("I2", inputs.second), Node("O"));
        gate.calc_output();
        gate.show();
    }

    cout << "\nTruth table for NOT gate:" << endl;
    vector<bool> not_truth_table = {false, true};
    for (const auto& input : not_truth_table) {
        GateNOT gate(Node("I1", input), Node("O"));
        gate.calc_output();
        gate.show();
    }

    return 0;
}
