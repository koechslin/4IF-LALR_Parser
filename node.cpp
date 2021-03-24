/*************************************************************************
                           Node  -  Implementation
                             -------------------
    début                : 23/02/2021
    copyright            : (C) 2021 par Killian OECHSLIN et Thomas MIGNOT
*************************************************************************/

//---------- Réalisation de la classe <Node> (fichier node.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <sstream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "node.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Node::ExporterNode(stringstream & nodes, stringstream & edges, int & nodeNumber) {
    int tmpNodeNumber = nodeNumber;
    nodes << "\tnode" << tmpNodeNumber << "[label=\"" << this->label << "\"];\n";

    if (this->child1 != nullptr) {
        nodeNumber++;
        edges << "\tnode" << tmpNodeNumber << " -> "
              << "node" << nodeNumber << ";\n";
        this->child1->ExporterNode(nodes, edges, nodeNumber);
    }
    if (this->child2 != nullptr) {
        nodeNumber++;
        edges << "\tnode" << tmpNodeNumber << " -> "
              << "node" << nodeNumber << ";\n";
        this->child2->ExporterNode(nodes, edges, nodeNumber);
    }
    if (this->child3 != nullptr) {
        nodeNumber++;
        edges << "\tnode" << tmpNodeNumber << " -> "
              << "node" << nodeNumber << ";\n";
        this->child3->ExporterNode(nodes, edges, nodeNumber);
    }
}
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées