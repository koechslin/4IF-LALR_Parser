/*************************************************************************
                           Symbole  -  Header file
                             -------------------
    début                : 23/02/2021
    copyright            : (C) 2021 par Killian OECHSLIN et Thomas MIGNOT
*************************************************************************/

//---------- Interface de la classe <Symbole> (fichier symbole.h) ----------------
#pragma once

//--------------------------------------------------- Interfaces utilisées
#include <string>

using namespace std;
//------------------------------------------------------------- Constantes
const string Etiquettes[] = {"OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR"};

//------------------------------------------------------------------ Types
enum Identificateurs { OPENPAR,
                       CLOSEPAR,
                       PLUS,
                       MULT,
                       INT,
                       FIN,
                       ERREUR,
                       EXPR };

//------------------------------------------------------------------------
// Rôle de la classe <Symbole>
//
//
//------------------------------------------------------------------------

class Symbole {
    //----------------------------------------------------------------- PUBLIC
  public:
    //----------------------------------------------------- Méthodes publiques
    virtual void Affiche();

    virtual bool IsTerminal();

    //------------------------------------------------- Surcharge d'opérateurs
    operator int() const {
        return ident;
    }

    //-------------------------------------------- Constructeurs - destructeur
    Symbole(int i)
        : ident(i) {}

    virtual ~Symbole() {}

    //------------------------------------------------------------------ PRIVE
  protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    int ident;
    bool isTerminal;
};

class Entier : public Symbole {
    //----------------------------------------------------------------- PUBLIC
  public:
    //----------------------------------------------------- Méthodes publiques
    virtual void Affiche();

    virtual int GetValeur();

    virtual bool IsTerminal();

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    Entier(int v)
        : Symbole(INT), valeur(v) {}

    ~Entier() {}

    //------------------------------------------------------------------ PRIVE
  protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    int valeur;
};
