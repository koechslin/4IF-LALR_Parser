/*************************************************************************
                           Node  -  Header file
                             -------------------
    début                : 23/02/2021
    copyright            : (C) 2021 par Killian OECHSLIN et Thomas MIGNOT
*************************************************************************/

//---------- Interface de la classe <Node> (fichier node.h) ----------------
#ifndef NODE_H
#define NODE_H

//--------------------------------------------------- Interfaces utilisées
#include <sstream>
#include <string>

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Node>
//
//
//------------------------------------------------------------------------
class Node {
    //----------------------------------------------------------------- PUBLIC
  public:
    //----------------------------------------------------- Méthodes publiques
    void ExporterNode(stringstream & nodes, stringstream & edges, int & nodeNumber);

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    Node(string label, Node * c1 = nullptr, Node * c2 = nullptr, Node * c3 = nullptr)
        : label(label), child1(c1), child2(c2), child3(c3){};

    virtual ~Node();

    //------------------------------------------------------------------ PRIVE
  protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    string label;
    Node * child1;
    Node * child2;
    Node * child3;
};

#endif