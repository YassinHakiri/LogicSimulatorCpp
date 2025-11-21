/*
 * GateAND.h
 *
 *  Created on: 14 déc. 2024
 *      Author: lenovo
 */

#pragma once
#include "Gate.h"

class GateAND : public Gate {
public:
    GateAND(const Node& input1, const Node& input2, const Node& out);

    int calc_output() override;
};
