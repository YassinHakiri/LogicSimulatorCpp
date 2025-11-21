//============================================================================
// Name        : 2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "node.h"
#include "Gate.h"
#include "GateAND.h"
#include <iostream>
#include <string>
using namespace std ;

int main() {
    // Créer une porte AND avec les nœuds I1 et I2 comme entrées et O comme sortie
    GateAND G1(Node("I1", true), Node("I2", true), Node("O"));

    // Calculer la sortie de la porte AND
    int result = G1.calc_output();
    if (result == 0) {
        cout << "Output computed successfully." << endl;
    } else {
        cout << "Output could not be computed." << endl;
    }

    // Afficher les valeurs des entrées et de la sortie de la porte AND
    G1.show();

    // Tester avec une autre combinaison d'entrées
    GateAND G2(Node("I1", true), Node("I2", false), Node("O"));
    result = G2.calc_output();
    if (result == 0) {
        cout << "Output computed successfully." << endl;
    } else {
        cout << "Output could not be computed." << endl;
    }
    G2.show();

    return 0;
}


/*
//  5. Table de vérité
int main() {
    // Table de vérité pour la porte AND
    vector<pair<bool, bool>> truth_table = {
        {false, false},
        {false, true},
        {true, false},
        {true, true}
    };

    for (const auto& inputs : truth_table) {
        GateAND gate(Node("I1", inputs.first), Node("I2", inputs.second), Node("O"));
        gate.calc_output();
        gate.show();
    }

    return 0;
}

*/
