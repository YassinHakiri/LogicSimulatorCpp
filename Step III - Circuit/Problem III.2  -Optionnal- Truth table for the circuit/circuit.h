#pragma once
#include <vector>
#include <string>
#include "node.h"
#include "Gate.h"

class circuit {
public:
    std::vector<Node> inputs;
    std::vector<Node> outputs;
    std::vector<Gate*> gates;

    void show_gates();
    void inputs_to_gates();
    void internal_outputs_to_inputs();
    bool are_all_outputs_computed();
    void compute();
    void gates_to_outputs();
    void reset();
    void clear_inputs();
    void compute_truth_table(); 
};