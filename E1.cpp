/*************************************************************************
                           E1  -  Implementation
                             -------------------
    début                : 23/02/2021
    copyright            : (C) 2021 par Killian OECHSLIN et Thomas MIGNOT
*************************************************************************/

//---------- Réalisation de la classe <E1> (fichier E1.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;
//------------------------------------------------------ Include personnel
#include "E1.h"
#include "E4.h"
#include "E5.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool E1::Transition(Automate & automate, Symbole * s) {
    switch(*s){
        case PLUS:
            automate.Decalage(s, new E4);
            break;
        case MULT:
            automate.Decalage(s, new E5);
            break;
        case FIN:
            return true; // Accepter
            break;
        default:
            automate.SetError();
            cout << "Erreur dans l'état E1 :" << endl;
            cout << "Symboles attendus : PLUS, MULT, FIN" << endl;
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