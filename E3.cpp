/*************************************************************************
                           E3  -  Implementation
                             -------------------
    début                : 23/02/2021
    copyright            : (C) 2021 par Killian OECHSLIN et Thomas MIGNOT
*************************************************************************/

//---------- Réalisation de la classe <E3> (fichier E3.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;
//------------------------------------------------------ Include personnel
#include "E3.h"
#include "Expr.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool E3::Transition(Automate & automate, Symbole * s) {
    Entier * entier;
    switch(*s){
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            entier = (Entier*) automate.PopSymbole();
            automate.Reduction(1, new Expr(entier->GetValeur()));
            delete(entier);
            break;
        default:
            automate.SetError();
            cout << "Erreur dans l'état E3 :" << endl;
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