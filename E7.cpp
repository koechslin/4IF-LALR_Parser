/*************************************************************************
                           E7  -  Implementation
                             -------------------
    début                : 23/02/2021
    copyright            : (C) 2021 par Killian OECHSLIN et Thomas MIGNOT
*************************************************************************/

//---------- Réalisation de la classe <E7> (fichier E7.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;
//------------------------------------------------------ Include personnel
#include "E5.h"
#include "E7.h"
#include "Expr.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool E7::Transition(Automate & automate, Symbole * s) {
    Expr * expr1;
    Expr * expr2;
    switch(*s){
        case PLUS:
        case CLOSEPAR:
        case FIN:
            expr1 = (Expr*) automate.PopSymbole();
            delete(automate.PopSymbole()); // On enlève le '+'
            expr2 = (Expr*) automate.PopSymbole();
            automate.Reduction(3, new Expr(expr1->GetValeur() + expr2->GetValeur()));
            delete(expr1);
            delete(expr2);
            break;
        case MULT:
            automate.Decalage(s, new E5);
            break;
        default:
            automate.SetError();
            cout << "Erreur dans l'état E7 :" << endl;
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