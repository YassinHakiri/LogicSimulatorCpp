/*
 * Gate.cpp
 *
 *  Created on: 14 déc. 2024
 *      Author: lenovo
 */
#include "Gate.h"
#include <iostream>
#include <string>
using namespace std ;

// Constructeur
Gate::Gate(const string& inName, const vector<Node>& inInputs)
    : name(inName), inputs(inInputs), output("output") {}

// Méthode pour afficher les valeurs des entrées et de la sortie
void Gate::show() const {
    for (const auto& input : inputs) {
        input.show_value();
    }
    cout << "| ";
    output.show_value();
}

// Méthode pour calculer la sortie (simulation d'une porte AND)
int Gate::calc_output() {
    // Commenté pour la partie F

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
        result = result && inputs[i].value;
    }
    output.set_value(result);
    return 0;

    return -1;
}




