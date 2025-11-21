//============================================================================
// Name        : 2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "node.h"

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
