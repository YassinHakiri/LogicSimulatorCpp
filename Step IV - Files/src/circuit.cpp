/*
 * circuit.cpp
 *
 *  Created on: 14 déc. 2024
 *      Author: lenovo
 */
#include <fstream>
#include <sstream>
#include <iostream>
#include "circuit.h"
#include "GateAND.h"
#include "GateOR.h"
#include "GateNOT.h"
#include <vector>
#include <string>
#include <cerrno>
#include <cstring>
using namespace std ;
// Charger la configuration des portes logiques a partir d'un fichier
int circuit::load_gates_from_file(string inFileName) {
   //verif if the function works
    cout << "Trying to open file: " << inFileName << endl;
    ifstream file(inFileName);
    if (!file) {
        // Print a detailed error message
        cerr << "Unable to open file: " << strerror(errno) << endl;
        return 1; // Return error code
    }

    // Loop to read lines from the file
    string line;
    while (std::getline(file, line)) {
        istringstream iss(line);
        string gateType;
        iss >> gateType;

        // Verifie et cree chaque type de porte ou entree/sortie
        if (gateType == "INPUT") {
            string inputName;
            while (iss >> inputName) { // Lit les noms des entrees
                inputs.push_back(Node(inputName)); // Create Node from input name
                cout << "INPUT: " << inputName << endl;
            }
        } else if (gateType == "OUTPUT") {
            string outputName;
            while (iss >> outputName) {
                outputs.push_back(Node(outputName)); // Create Node from output name
                cout << "OUTPUT: " << outputName << endl;
            }
        } else if (gateType == "AND") {
            string outputName, input1Name, input2Name;
            iss >> outputName >> input1Name >> input2Name;
            gates.push_back(new GateAND(Node(input1Name), Node(input2Name), Node(outputName)));
            cout << "AND: " << input1Name << " " << input2Name << " " << outputName << endl;
        } else if (gateType == "OR") {
            string outputName, input1Name, input2Name;
            iss >> outputName >> input1Name >> input2Name;
            gates.push_back(new GateOR(Node(input1Name), Node(input2Name), Node(outputName)));
            cout << "OR: " << input1Name << " " << input2Name << " " << outputName << endl;
        } else if (gateType == "NOT") {
            string outputName, input1Name;
            iss >> outputName >> input1Name;
            gates.push_back(new GateNOT(Node(input1Name), Node(outputName)));
            cout << "NOT: " << input1Name << " " << outputName << endl;
        } else {
            cerr << "Unknown gate type: " << gateType << endl;
        }
    }

    // Close the file after processing
    file.close();
    return 0; // Success
}
int circuit::load_inputs_from_file(const string& inFileName) {
    // Ouvrir le fichier
    //verif if the function works
    cout << "Trying to open file: " << inFileName << endl;
    ifstream file(inFileName);
    if (!file) {
        cerr << "Unable to open file: " << strerror(errno) << endl;
        return 1; // Code d'erreur
    }

    // Lire le nombre de tests
    int numTests;
    file >> numTests;
    cout << "Number of tests: " << numTests << endl;

    // Lire chaque ligne d'entrees et calculer les sorties
    for (int test = 1; test <= numTests; ++test) {
        string inputLine;
        file >> inputLine;

        // Verification de la longueur des entrees
        if (inputLine.length() != inputs.size()) {
            cerr << "Error: Input line length (" << inputLine.length()
                      << ") does not match number of inputs (" << inputs.size() << ")" << endl;
            continue;
        }

        // Definir les valeurs des entrees
        for (size_t i = 0; i < inputs.size(); ++i) {
            bool value = (inputLine[i] == '1');
            inputs[i].set_value(value);
        }

        cout << "Test " << test << ": Inputs = " << inputLine << endl;

        // Reinitialiser et calculer le circuit
        reset();
        compute();

        // Afficher les sorties
        cout << "Outputs: ";
        for (const auto& output : outputs) {
            output.show_value();
        }
    cout <<endl;
    }

    file.close();
    return 0; // Succes
}


//*************************************************************************************

// Show gates method
void circuit::show_gates() {
    for (auto gate : gates) {
        std::cout << typeid(*gate).name() << " << ";
        for (const auto& input : gate->inputs) {
            std::cout << input.name << " :" << (input.already_computed ? (input.value ? "1" : "0") : "?") << " ";
        }
        std::cout << ">> " << gate->output.name << " :" << (gate->output.already_computed ? (gate->output.value ? "1" : "0") : "?") << "\n";
    }
}

// Inputs to gates method
void circuit::inputs_to_gates() {
    for (auto& gate : gates) {
        for (auto& gate_input : gate->inputs) {
            for (const auto& circuit_input : inputs) {
                if (gate_input.name == circuit_input.name) {
                    gate_input.value = circuit_input.value;
                    gate_input.already_computed = circuit_input.already_computed;
                }
            }
        }
    }
}

// Internal outputs to inputs method
void circuit::internal_outputs_to_inputs() {
    for (auto& gate : gates) {
        if (gate->output.already_computed) {
            for (auto& other_gate : gates) {
                for (auto& input : other_gate->inputs) {
                    if (input.name == gate->output.name) {
                        input.value = gate->output.value;
                        input.already_computed = true;
                    }
                }
            }
        }
    }
}

// Are all outputs computed method
bool circuit::are_all_outputs_computed() {
    for (const auto& gate : gates) {
        if (!gate->output.already_computed) {
            return false;
        }
    }
    return true;
}

// Compute method
void circuit::compute() {
    inputs_to_gates();
    for (int i = 0; i < 3; ++i) { // Repeat a few times to ensure propagation
        for (auto& gate : gates) {
            gate->calc_output();
        }
        internal_outputs_to_inputs();
        if (are_all_outputs_computed()) {
            break;
        }
    }
    gates_to_outputs();
}

// Gates to outputs method
void circuit::gates_to_outputs() {
    for (auto& output : outputs) {
        for (const auto& gate : gates) {
            if (output.name == gate->output.name) {
                output.value = gate->output.value;
                output.already_computed = gate->output.already_computed;
            }
        }
    }
}

// Reset method
void circuit::reset() {
    for (auto& gate : gates) {
        gate->output.already_computed = false;
        for (auto& input : gate->inputs) {
            input.already_computed = false;
        }
    }
}

// Clear inputs method
void circuit::clear_inputs() {
    for (auto& input : inputs) {
        input.value = false;
        input.already_computed = false;
    }
}




