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
const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR" };

//------------------------------------------------------------------ Types
enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR };

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

      //------------------------------------------------- Surcharge d'opérateurs
      operator int() const { return ident; }

      //-------------------------------------------- Constructeurs - destructeur
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }

   //------------------------------------------------------------------ PRIVE
   protected:
      //----------------------------------------------------- Méthodes protégées

      //----------------------------------------------------- Attributs protégés
      int ident;
};

class Entier : public Symbole {
   //----------------------------------------------------------------- PUBLIC
   public:
      //----------------------------------------------------- Méthodes publiques
      virtual void Affiche();

      //------------------------------------------------- Surcharge d'opérateurs

      //-------------------------------------------- Constructeurs - destructeur
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }

   //------------------------------------------------------------------ PRIVE
   protected:
      //----------------------------------------------------- Méthodes protégées

      //----------------------------------------------------- Attributs protégés
      int valeur;
};

