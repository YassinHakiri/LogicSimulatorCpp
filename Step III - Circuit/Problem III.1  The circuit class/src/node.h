/*
 * node.h
 *
 *  Created on: 14 déc. 2024
 *      Author: lenovo
 */

#pragma once
#include <string>
#include <iostream>

using namespace std ;

class Node {
public:
    std::string name;
    bool value;
    bool already_computed;

    // Constructeur 1
    Node(const std::string& inName);

    // Constructeur 2
    Node(const std::string& inName, bool inValue);

    // Fonction membre pour définir la valeur
    void set_value(bool inValue);

    // Fonction membre pour afficher la valeur
    void show_value() const;
};
