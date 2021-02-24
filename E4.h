/*************************************************************************
                           E4  -  Header file
                             -------------------
    début                : 23/02/2021
    copyright            : (C) 2021 par Killian OECHSLIN et Thomas MIGNOT
*************************************************************************/

//---------- Interface de la classe <E4> (fichier E4.h) ----------------
#pragma once

//--------------------------------------------------- Interfaces utilisées
#include "etat.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <E4>
//
//
//------------------------------------------------------------------------


class E4 : public Etat {
   //----------------------------------------------------------------- PUBLIC
   public:
      //----------------------------------------------------- Méthodes publiques
      virtual bool Transition(Automate & automate, Symbole * s);

      //------------------------------------------------- Surcharge d'opérateurs

      //-------------------------------------------- Constructeurs - destructeur
      E4() : Etat("E4") {};
      virtual ~E4() {};
   //------------------------------------------------------------------ PRIVE
   protected:
      //----------------------------------------------------- Méthodes protégées

      //----------------------------------------------------- Attributs protégés
};
