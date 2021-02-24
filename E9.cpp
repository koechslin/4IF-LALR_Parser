/*************************************************************************
                           E9  -  Implementation
                             -------------------
    début                : 23/02/2021
    copyright            : (C) 2021 par Killian OECHSLIN et Thomas MIGNOT
*************************************************************************/

//---------- Réalisation de la classe <E9> (fichier E9.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;
//------------------------------------------------------ Include personnel
#include "E9.h"
#include "Expr.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool E9::Transition(Automate & automate, Symbole * s) {
    Expr * expr;
    switch(*s){
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            delete(automate.PopSymbole()); // On enlève ')'
            expr = (Expr*) automate.PopSymbole();
            delete(automate.PopSymbole()); // On enlève '('
            automate.Reduction(3, expr);
            break;
        default:
            automate.SetError();
            cout << "Erreur dans l'état E9 :" << endl;
            cout << "Symboles attendus : PLUS, MULT, CLOSEPAR, FIN" << endl;
            cout << "Symbole lu : ";
            s->Affiche();
            cout << endl;
            return true;
    }
    return false;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées