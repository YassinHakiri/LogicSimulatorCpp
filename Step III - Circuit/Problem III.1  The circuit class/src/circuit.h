/*
 * circuit.h
 *
 *  Created on: 14 déc. 2024
 *      Author: lenovo
 */

#pragma once
#include <vector>
#include <iostream>
#include <typeinfo>
#include "node.h"
#include "Gate.h"

class circuit {
public:
    std::vector<Node> inputs;
    std::vector<Node> outputs;
    std::vector<Gate*> gates;

    void show_gates();
    void inputs_to_gates();
    void gates_to_outputs();
    void internal_outputs_to_inputs();
    bool are_all_outputs_computed();
    void reset();
    void clear_inputs();
    void compute();
};
