#include "node.h"
#include "Gate.h"
#include <iostream>
#include <string>
using namespace std ;
int main() {
    // Créer les nœuds A, B et C
    Node A("A");
    Node B("B");
    Node C("C", true);

    // Modifier les valeurs des nœuds A et B
    A.set_value(true);
    B.set_value(false);

    // Créer une porte avec les nœuds A et B comme entrées
    vector<Node> inputs = {A, B};
    Gate andGate("AND", inputs);

    // Afficher les valeurs initiales des entrées et de la sortie de la porte
    andGate.show();

    // Calculer la sortie de la porte
    int result = andGate.calc_output();
    if (result == 0) {
        cout << "Output computed successfully." << endl;
    } else {
        cout << "Output could not be computed." << endl;
    }

    // Afficher les nouvelles valeurs des entrées et de la sortie de la porte
    andGate.show();

    return 0;
}