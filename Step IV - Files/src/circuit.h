/*
 * circuit.h
 *
 *  Created on: 14 déc. 2024
 *      Author: lenovo
 */

#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <typeinfo>
#include "node.h"
#include "Gate.h"
using namespace std ;
class circuit {
public:
    vector<Node> inputs;
    vector<Node> outputs;
    vector<Node> intermediate_nodes;  //Stocker les noeuds intermediaires
    vector<Gate*> gates; //Stocker les pointeurs vers les objets Gate repr�sentant les portes logiques du circuit.

    void inputs_to_gates(); //Connecter les entrees du circuit aux portes logiques.
    void internal_outputs_to_inputs();
    bool are_all_outputs_computed();
    void compute();
    void gates_to_outputs();
    void reset();
    void clear_inputs();
   // void compute_truth_table();
    int load_gates_from_file(const string inFileName);
    int load_inputs_from_file(const string& inFileName);
    void show_outputs() ;
    void show_gates() ;

};
