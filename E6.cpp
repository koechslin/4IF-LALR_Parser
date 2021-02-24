/*************************************************************************
                           E6  -  Implementation
                             -------------------
    début                : 23/02/2021
    copyright            : (C) 2021 par Killian OECHSLIN et Thomas MIGNOT
*************************************************************************/

//---------- Réalisation de la classe <E6> (fichier E6.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;
//------------------------------------------------------ Include personnel
#include "E4.h"
#include "E5.h"
#include "E6.h"
#include "E9.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool E6::Transition(Automate & automate, Symbole * s) {
    switch(*s){
        case PLUS:
            automate.Decalage(s, new E4);
            break;
        case MULT:
            automate.Decalage(s, new E5);
            break;
        case CLOSEPAR:
            automate.Decalage(s,new E9);
            break;
        default:
            automate.SetError();
            cout << "Erreur dans l'état E6 :" << endl;
            cout << "Symboles attendus : PLUS, MULT, CLOSEPAR" << endl;
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