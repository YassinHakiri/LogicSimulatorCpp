#pragma once
#include "Gate.h"

class GateNOT : public Gate {
public:
    GateNOT(const Node& input, const Node& out);

    int calc_output() override;
};