/*************************************************************************
                           Etat  -  Header file
                             -------------------
    début                : 23/02/2021
    copyright            : (C) 2021 par Killian OECHSLIN et Thomas MIGNOT
*************************************************************************/

//---------- Interface de la classe <Etat> (fichier etat.h) ----------------
#ifndef ETAT_H
#define ETAT_H

//--------------------------------------------------- Interfaces utilisées
#include "automate.h"
#include "symbole.h"
#include <string>

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

    void AfficherErreur(Automate & automate, Symbole * s, string etat, string grammaireAutorisee);

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    Etat(string name)
        : name(name){};

    virtual ~Etat(){};

    //------------------------------------------------------------------ PRIVE
  protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    string name;
};

//---------- Interface de la classe <E0> (fichier etat.h) ----------------
class E0 : public Etat {
    //----------------------------------------------------------------- PUBLIC
  public:
    //----------------------------------------------------- Méthodes publiques
    virtual bool Transition(Automate & automate, Symbole * s);

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    E0()
        : Etat("E0"){};

    virtual ~E0(){};

    //------------------------------------------------------------------ PRIVE
  protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//---------- Interface de la classe <E1> (fichier etat.h) ----------------
class E1 : public Etat {
    //----------------------------------------------------------------- PUBLIC
  public:
    //----------------------------------------------------- Méthodes publiques
    virtual bool Transition(Automate & automate, Symbole * s);

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    E1()
        : Etat("E1"){};

    virtual ~E1(){};

    //------------------------------------------------------------------ PRIVE
  protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//---------- Interface de la classe <E2> (fichier etat.h) ----------------
class E2 : public Etat {
    //----------------------------------------------------------------- PUBLIC
  public:
    //----------------------------------------------------- Méthodes publiques
    virtual bool Transition(Automate & automate, Symbole * s);

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    E2()
        : Etat("E2"){};

    virtual ~E2(){};

    //------------------------------------------------------------------ PRIVE
  protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//---------- Interface de la classe <E3> (fichier etat.h) ----------------
class E3 : public Etat {
    //----------------------------------------------------------------- PUBLIC
  public:
    //----------------------------------------------------- Méthodes publiques
    virtual bool Transition(Automate & automate, Symbole * s);

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    E3()
        : Etat("E3"){};

    virtual ~E3(){};

    //------------------------------------------------------------------ PRIVE
  protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//---------- Interface de la classe <E4> (fichier etat.h) ----------------
class E4 : public Etat {
    //----------------------------------------------------------------- PUBLIC
  public:
    //----------------------------------------------------- Méthodes publiques
    virtual bool Transition(Automate & automate, Symbole * s);

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    E4()
        : Etat("E4"){};

    virtual ~E4(){};

    //------------------------------------------------------------------ PRIVE
  protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//---------- Interface de la classe <E5> (fichier etat.h) ----------------
class E5 : public Etat {
    //----------------------------------------------------------------- PUBLIC
  public:
    //----------------------------------------------------- Méthodes publiques
    virtual bool Transition(Automate & automate, Symbole * s);

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    E5()
        : Etat("E5"){};

    virtual ~E5(){};

    //------------------------------------------------------------------ PRIVE
  protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//---------- Interface de la classe <E6> (fichier etat.h) ----------------
class E6 : public Etat {
    //----------------------------------------------------------------- PUBLIC
  public:
    //----------------------------------------------------- Méthodes publiques
    virtual bool Transition(Automate & automate, Symbole * s);

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    E6()
        : Etat("E6"){};

    virtual ~E6(){};

    //------------------------------------------------------------------ PRIVE
  protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//---------- Interface de la classe <E7> (fichier etat.h) ----------------
class E7 : public Etat {
    //----------------------------------------------------------------- PUBLIC
  public:
    //----------------------------------------------------- Méthodes publiques
    virtual bool Transition(Automate & automate, Symbole * s);

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    E7()
        : Etat("E7"){};

    virtual ~E7(){};

    //------------------------------------------------------------------ PRIVE
  protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//---------- Interface de la classe <E8> (fichier etat.h) ----------------
class E8 : public Etat {
    //----------------------------------------------------------------- PUBLIC
  public:
    //----------------------------------------------------- Méthodes publiques
    virtual bool Transition(Automate & automate, Symbole * s);

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    E8()
        : Etat("E8"){};

    virtual ~E8(){};

    //------------------------------------------------------------------ PRIVE
  protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//---------- Interface de la classe <E9> (fichier etat.h) ----------------
class E9 : public Etat {
    //----------------------------------------------------------------- PUBLIC
  public:
    //----------------------------------------------------- Méthodes publiques
    virtual bool Transition(Automate & automate, Symbole * s);

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    E9()
        : Etat("E9"){};

    virtual ~E9(){};

    //------------------------------------------------------------------ PRIVE
  protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

#endif