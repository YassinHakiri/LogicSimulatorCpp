/*
 * node.cpp
 *
 *  Created on: 14 déc. 2024
 *      Author: lenovo
 */
#include "node.h"
#include <iostream>
#include <iostream>
#include <string>
using namespace std ;
// Constructeur 1
Node::Node(const string& inName) : name(inName), value(false), already_computed(false) {}

// Constructeur 2
Node::Node(const string& inName, bool inValue) : name(inName), value(inValue), already_computed(true) {}

// Fonction membre pour définir la valeur
void Node::set_value(bool inValue) {
    value = inValue;
    already_computed = true;
}

// Fonction membre pour afficher la valeur
void Node::show_value() const {
    if (already_computed) {
        cout << name << ": " << (value ? "1" : "0") << endl;
    } else {
        cout << name << ": ?" << endl;
    }
}



