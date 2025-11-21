/*
 * node.h
 *
 *  Created on: 14 déc. 2024
 *      Author: lenovo
 */

#pragma once
//Une directive pour éviter les inclusions multiples du fichier d'en-tête dans le même fichier source.
#include <string>
#include <iostream>

using namespace std ;
// Déclaration de la classe Node.
class Node {
public:
    string name;
    bool value;
    bool already_computed;

    // Constructeur 1
    Node(const string& inName);

    // Constructeur 2 :initialise un Node avec un nom et une valeur initiale.
    Node(const string& inName, bool inValue);

    // Fonction membre pour définir ou mettre à jour la valeur du nœud.
    void set_value(bool inValue);

    // Fonction membre pour afficher la valeur du nœud.
    void show_value() const;
};
