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

   // Methode pour calculer la sortie, redefinie de la classe de base
    int calc_output() override;
};
