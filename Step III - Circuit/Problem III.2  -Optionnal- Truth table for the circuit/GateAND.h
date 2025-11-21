#pragma once
#include "Gate.h"

class GateAND : public Gate {
public:
    GateAND(const Node& input1, const Node& input2, const Node& out);

    int calc_output() override;
};