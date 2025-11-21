/*
 * circuit.cpp
 *
 *  Created on: 14 déc. 2024
 *      Author: lenovo
 */
#include "circuit.h"

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



