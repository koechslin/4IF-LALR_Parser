/*************************************************************************
                           E8  -  Implementation
                             -------------------
    début                : 23/02/2021
    copyright            : (C) 2021 par Killian OECHSLIN et Thomas MIGNOT
*************************************************************************/

//---------- Réalisation de la classe <E8> (fichier E8.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;
//------------------------------------------------------ Include personnel
#include "E8.h"
#include "Expr.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool E8::Transition(Automate & automate, Symbole * s) {
    Expr * expr1;
    Expr * expr2;
    switch(*s){
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            expr1 = (Expr*) automate.PopSymbole();
            delete(automate.PopSymbole()); // On enlève le '*'
            expr2 = (Expr*) automate.PopSymbole();
            automate.Reduction(3, new Expr(expr1->GetValeur() * expr2->GetValeur()));
            delete(expr1);
            delete(expr2);
            break;
        default:
            automate.SetError();
            cout << "Erreur dans l'état E8 :" << endl;
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