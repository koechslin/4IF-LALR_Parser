/*************************************************************************
                           E2  -  Implementation
                             -------------------
    début                : 23/02/2021
    copyright            : (C) 2021 par Killian OECHSLIN et Thomas MIGNOT
*************************************************************************/

//---------- Réalisation de la classe <E2> (fichier E2.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;
//------------------------------------------------------ Include personnel
#include "E2.h"
#include "E3.h"
#include "E6.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool E2::Transition(Automate & automate, Symbole * s) {
    switch(*s){
        case INT:
            automate.Decalage(s, new E3);
            break;
        case OPENPAR:
            automate.Decalage(s, new E2);
            break;
        case EXPR:
            automate.Decalage(s, new E6);
            break;
        default:
            automate.SetError();
            cout << "Erreur dans l'état E2 :" << endl;
            cout << "Symboles attendus : INT, OPENPAR, EXPR" << endl;
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