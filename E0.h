/*************************************************************************
                           E0  -  Header file
                             -------------------
    début                : 23/02/2021
    copyright            : (C) 2021 par Killian OECHSLIN et Thomas MIGNOT
*************************************************************************/

//---------- Interface de la classe <E0> (fichier E0.h) ----------------
#pragma once

//--------------------------------------------------- Interfaces utilisées
#include "etat.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <E0>
//
//
//------------------------------------------------------------------------


class E0 : public Etat {
   //----------------------------------------------------------------- PUBLIC
   public:
      //----------------------------------------------------- Méthodes publiques
      virtual bool Transition(Automate & automate, Symbole * s);

      //------------------------------------------------- Surcharge d'opérateurs

      //-------------------------------------------- Constructeurs - destructeur
      E0() : Etat("E0") {};
      virtual ~E0() {};
   //------------------------------------------------------------------ PRIVE
   protected:
      //----------------------------------------------------- Méthodes protégées

      //----------------------------------------------------- Attributs protégés
};

