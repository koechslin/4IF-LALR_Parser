#include "automate.h"
#include "lexer.h"

#include <iostream>
#include <string.h>

using namespace std;

void AfficherAide() {
    cout << "\nUtilisation : ./parser [-t] EXPRESSION" << endl
         << endl;

    cout << "Pour éviter tout conflit avec le terminal vous pouvez entourer l'expression avec des guillemets" << endl
         << endl;
    cout << "La grammaire autorisée est : + * ( ) INT" << endl
         << endl;
    cout << "  -t \tPermet de générer le fichier 'arbre.png' qui représente l'arbre syntaxique de l'expression saisie" << endl
         << endl;
}

int main(int argc, char ** argv) {
    bool afficherArbre = false;
    string chaine;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            AfficherAide();
            return 0;
        } else if (strcmp(argv[i], "-t") == 0) {
            afficherArbre = true;
        } else if (chaine.empty()) {
            chaine = argv[i];
        } else {
            cout << "Vous avez spécifié trop d'arguments ! !" << endl
                 << "Tapez './parser -h' pour avoir plus d'informations." << endl;
            return 0;
        }
    }

    if (chaine.empty()) {
        cout << "Vous devez spécifier une expression au moment de lancer le programme !" << endl
             << "Tapez './parser -h' pour avoir plus d'informations." << endl;
        return 0;
    }

    Lexer l(chaine);
    Automate a(&l);
    a.Lecture();

    if (afficherArbre && !a.GetError()) {
        a.ExporterArbre();
    }

    return 0;
}
