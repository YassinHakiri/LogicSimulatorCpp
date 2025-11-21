//============================================================================
// Name        : Step.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "circuit.h"
#include "GateAND.h"
#include "GateOR.h"
#include "GateNOT.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;
int main() {
    circuit myCircuit;
    string gatesFile = "gates.txt";
    string inputsFile = "inputs.txt";

    // Charger les portes depuis le fichier
    if (myCircuit.load_gates_from_file(gatesFile) != 0) {
        return 1;
    }

    // Charger les entrees et calculer les sorties
     if (myCircuit.load_inputs_from_file(inputsFile) != 0) {
        return 1;
    }

    return 0;
}
