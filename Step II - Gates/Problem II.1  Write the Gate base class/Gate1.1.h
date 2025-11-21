#pragma once
#include <vector>
#include "node.h"
#include <iostream>
#include <string>
using namespace std ;

/*
class Gate {
public:
    string name;
    vector<Node> inputs;
    Node output;

    Gate(const string& inName, const vector<Node>& inInputs);

    void show() const;
    virtual int calc_output();
};

*/

 //  Réponse à la question E
 
 
 class Gate {
public:
    string name;
    vector<Node> inputs;
    Node output;

    Gate(const string& inName, const vector<Node>& inInputs);

    void show() const;
    virtual int calc_output(); // Méthode virtuelle
};