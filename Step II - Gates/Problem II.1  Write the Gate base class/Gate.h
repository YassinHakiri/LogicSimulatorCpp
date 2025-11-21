#pragma once
#include <vector>
#include "node.h"
#include <iostream>
#include <string>
using namespace std ;

class Gate {
public:
    string name;
    vector<Node> inputs;
    Node output;

    Gate(const std::string& inName, const std::vector<Node>& inInputs);

    void show() const;
    virtual int calc_output();
};
