/*************************************************************************
                           Lexer  -  Header file
                             -------------------
    début                : 23/02/2021
    copyright            : (C) 2021 par Killian OECHSLIN et Thomas MIGNOT
*************************************************************************/

//---------- Interface de la classe <Lexer> (fichier lexer.h) ----------------
#pragma once

//--------------------------------------------------- Interfaces utilisées
#include "symbole.h"
#include <string>

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Lexer>
//
//
//------------------------------------------------------------------------

class Lexer {
    //----------------------------------------------------------------- PUBLIC
  public:
    //----------------------------------------------------- Méthodes publiques
    Symbole * Consulter();

    void Avancer();

    string GetFlux();

    int GetTete();

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    Lexer(string s)
        : flux(s), tete(0), tampon(nullptr) {}

    ~Lexer() {}

    //------------------------------------------------------------------ PRIVE
  protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    string flux;
    int tete;
    Symbole * tampon;
};
