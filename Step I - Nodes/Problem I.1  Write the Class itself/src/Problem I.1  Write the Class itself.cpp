//============================================================================
// Name        : 1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

class Node {
public:
    std::string name;
    bool value;
    bool already_computed;

    // Constructeur 1
    Node(const std::string& inName) : name(inName), value(false), already_computed(false) {}

    // Constructeur 2
    Node(const std::string& inName, bool inValue) : name(inName), value(inValue), already_computed(true) {}

    // Fonction membre pour définir la valeur
    void set_value(bool inValue) {
        value = inValue;
        already_computed = true;
    }

    // Fonction membre pour afficher la valeur
    void show_value() const {
        if (already_computed) {
            std::cout << name << ": " << (value ? "1" : "0") << std::endl;
        } else {
            std::cout << name << ": ?" << std::endl;
        }
    }
};

int main() {
    // Créer les nœuds A, B et C
    Node A("A");
    Node B("B");
    Node C("C", true);

    // Afficher les valeurs initiales des nœuds
    A.show_value();
    B.show_value();
    C.show_value();

    // Modifier les valeurs des nœuds A et B
    A.set_value(true);
    B.set_value(false);

    // Afficher les nouvelles valeurs des nœuds
    A.show_value();
    B.show_value();
    C.show_value();

    return 0;
}
