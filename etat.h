/*************************************************************************
                           Etat  -  Header file
                             -------------------
    début                : 23/02/2021
    copyright            : (C) 2021 par Killian OECHSLIN et Thomas MIGNOT
*************************************************************************/

//---------- Interface de la classe <Etat> (fichier etat.h) ----------------
#pragma once

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "symbole.h"
#include "automate.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Etat>
//
//
//------------------------------------------------------------------------


class Etat {
   //----------------------------------------------------------------- PUBLIC
   public:
      //----------------------------------------------------- Méthodes publiques
      void Afficher() const;
      virtual bool Transition(Automate & automate, Symbole * s) = 0;

      //------------------------------------------------- Surcharge d'opérateurs

      //-------------------------------------------- Constructeurs - destructeur
      Etat(string name) : name(name) {};
      virtual ~Etat() {};
   //------------------------------------------------------------------ PRIVE
   protected:
      //----------------------------------------------------- Méthodes protégées
      string name;

      //----------------------------------------------------- Attributs protégés
};

