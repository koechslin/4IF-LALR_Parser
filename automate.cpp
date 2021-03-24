/*************************************************************************
                           Automate  -  Implementation
                             -------------------
    début                : 23/02/2021
    copyright            : (C) 2021 par Killian OECHSLIN et Thomas MIGNOT
*************************************************************************/

//---------- Réalisation de la classe <Automate> (fichier automate.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;
//------------------------------------------------------ Include personnel
#include "Expr.h"
#include "automate.h"
#include "etat.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Automate::Reduction(int n, Symbole * s) {
    for (int i = 0; i < n; i++) {
        delete (pileEtats.back());
        pileEtats.pop_back();
    }

    pileEtats.back()->Transition(*this, s);
}

void Automate::Decalage(Symbole * s, Etat * e) {
    pileSymboles.push_back(s);
    pileEtats.push_back(e);
    if (s->IsTerminal()) {
        lexer->Avancer();
    }
}

void Automate::Lecture() {
    Symbole * s;
    bool fin = false;
    while (!fin) {
        s = lexer->Consulter();
        fin = pileEtats.back()->Transition(*this, s);
    }

    if (!error) {
        cout << "Résultat final : " << ((Expr *)pileSymboles.back())->GetValeur() << endl;
    }
    // On libère la mémoire
    for (int i = pileSymboles.size() - 1; i >= 0; i--) {
        delete (pileSymboles.back());
        pileSymboles.pop_back();
    }

    for (int i = pileEtats.size() - 1; i >= 0; i--) {
        delete (pileEtats.back());
        pileEtats.pop_back();
    }

    delete (s);
}

Symbole * Automate::PopSymbole() {
    Symbole * s = pileSymboles.back();
    pileSymboles.pop_back();
    return s;
}

void Automate::SetError() {
    error = true;
}

void Automate::AjouterNode(Node * node) {
    this->treeNodes.push_back(node);
}

Node * Automate::PopNode() {
    Node * ret = this->treeNodes.back();
    this->treeNodes.pop_back();
    return ret;
}

void Automate::ExporterArbre() {
    stringstream nodes;
    stringstream edges;
    int n = 0;
    this->treeNodes.back()->ExporterNode(nodes, edges, n);

    ofstream tmpDotFile("tmp.dot");
    if (tmpDotFile.is_open()) {
        tmpDotFile << "digraph {\n"
                      "\tordering=out;\n"
                      "\tranksep=.4;\n"
                      "\tnode [shape=box, fixedsize=false, fontsize=12, fontname=\"Helvetica\", fontcolor=\"blue\"\n"
                      "\t\twidth=.25, height=.25, color=\"black\", fillcolor=\"lightgrey\", style=\"filled, solid\"];\n"
                      "\tedge [arrowsize=.5, color=\"black\"]\n\n" +
                          nodes.str() + edges.str() + "}\n";

        tmpDotFile.close();
        system("dot -Tpng -o arbre.png tmp.dot");
    } else {
        cout << "Erreur lors de la création du fichier intermédiaire 'tmp.dot'" << endl;
    }
}

bool Automate::GetError() {
    return this->error;
}

Lexer * Automate::GetLexer() {
    return this->lexer;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Automate::Automate(Lexer * l)
    : lexer(l), error(false) {
    pileEtats.push_back(new E0);
}

Automate::~Automate() {
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées