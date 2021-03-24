/*************************************************************************
                           Automate  -  Header file
                             -------------------
    début                : 23/02/2021
    copyright            : (C) 2021 par Killian OECHSLIN et Thomas MIGNOT
*************************************************************************/

//---------- Interface de la classe <Automate> (fichier automate.h) ----------------
#pragma once

//--------------------------------------------------- Interfaces utilisées
#include "lexer.h"
#include "symbole.h"
#include <deque>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Automate>
//
//
//------------------------------------------------------------------------
class Etat;
class Automate {
    //----------------------------------------------------------------- PUBLIC
  public:
    //----------------------------------------------------- Méthodes publiques
    void Decalage(Symbole * s, Etat * e);

    void Reduction(int n, Symbole * s);

    void Lecture();

    void Accepter();

    Symbole * PopSymbole();

    void SetError();

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    Automate(Lexer * l);

    virtual ~Automate();

    //------------------------------------------------------------------ PRIVE
  protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    deque<Etat *> pileEtats;
    deque<Symbole *> pileSymboles;
    Lexer * lexer;
    bool error;
};
