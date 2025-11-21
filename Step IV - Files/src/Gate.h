/*
 * Gate.h
 *
 *  Created on: 14 déc. 2024
 *      Author: lenovo
 */

#pragma once
#include <vector>
#include "node.h"
#include <iostream>
#include <string>
using namespace std ;

 class Gate {
public:
    string name;
    vector<Node> inputs; // Vecteur pour stocker les entrees de la porte
    Node output; // Sortie de la porte

   // Constructeur de la classe Gate

    Gate(const string& inName, const vector<Node>& inInputs);

    void show() const;
    virtual int calc_output(); // Methode virtuelle
};

