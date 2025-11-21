/*
 * GateNOT.h
 *
 *  Created on: 14 déc. 2024
 *      Author: lenovo
 */

#pragma once
#include "Gate.h"

class GateNOT : public Gate {
public:
    GateNOT(const Node& input, const Node& out);

    int calc_output() override;
};
