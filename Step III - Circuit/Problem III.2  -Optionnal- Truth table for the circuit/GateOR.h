#pragma once
#include "Gate.h"

class GateOR : public Gate {
public:
    GateOR(const Node& input1, const Node& input2, const Node& out);

    int calc_output() override;
};