/*************************************************************************
                           Symbole  -  Implementation
                             -------------------
    début                : 23/02/2021
    copyright            : (C) 2021 par Killian OECHSLIN et Thomas MIGNOT
*************************************************************************/

//---------- Réalisation de la classe <Symbole> (fichier symbole.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;
//------------------------------------------------------ Include personnel
#include "symbole.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Symbole::Affiche() {
    cout << Etiquettes[ident];
}

bool Symbole::IsTerminal() {
    return true;
}

void Entier::Affiche() {
    Symbole::Affiche();
    cout << "(" << valeur << ")";
}

int Entier::GetValeur() {
    return valeur;
}

bool Entier::IsTerminal() {
    return true;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées