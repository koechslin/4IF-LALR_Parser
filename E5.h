/*************************************************************************
                           E5  -  Header file
                             -------------------
    début                : 23/02/2021
    copyright            : (C) 2021 par Killian OECHSLIN et Thomas MIGNOT
*************************************************************************/

//---------- Interface de la classe <E5> (fichier E5.h) ----------------
#pragma once

//--------------------------------------------------- Interfaces utilisées
#include "etat.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <E5>
//
//
//------------------------------------------------------------------------


class E5 : public Etat {
   //----------------------------------------------------------------- PUBLIC
   public:
      //----------------------------------------------------- Méthodes publiques
      virtual bool Transition(Automate & automate, Symbole * s);

      //------------------------------------------------- Surcharge d'opérateurs

      //-------------------------------------------- Constructeurs - destructeur
      E5() : Etat("E5") {};
      virtual ~E5() {};
   //------------------------------------------------------------------ PRIVE
   protected:
      //----------------------------------------------------- Méthodes protégées

      //----------------------------------------------------- Attributs protégés
};

