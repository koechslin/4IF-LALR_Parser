/*************************************************************************
                           Automate  -  Implementation
                             -------------------
    début                : 23/02/2021
    copyright            : (C) 2021 par Killian OECHSLIN et Thomas MIGNOT
*************************************************************************/

//---------- Réalisation de la classe <Automate> (fichier automate.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;
//------------------------------------------------------ Include personnel
#include "automate.h"
#include "E0.h"
#include "Expr.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Automate::Reduction(int n, Symbole* s) {
  for(int i=0;i<n;i++){
    delete(pileEtats.back());
    pileEtats.pop_back();
  }

  pileEtats.back()->Transition(*this, s);
}

void Automate::Decalage(Symbole * s, Etat * e) {
  pileSymboles.push_back(s);
  pileEtats.push_back(e);
  if(s->IsTerminal()) {
    lexer->Avancer();
  }
}

void Automate::Lecture() {
  Symbole * s;
  bool fin = false;
  while(!fin) {
    s = lexer->Consulter();
    fin = pileEtats.back()->Transition(*this, s);
  }

  if(!error) {
    cout << "Résultat final : " << ((Expr*) pileSymboles.back())->GetValeur() << endl;
  }
  // On libère la mémoire
  for(int i = pileSymboles.size() - 1; i>=0; i--) {
    delete(pileSymboles.back());
    pileSymboles.pop_back();
  }

  for(int i = pileEtats.size() - 1; i>=0; i--) {
    delete(pileEtats.back());
    pileEtats.pop_back();
  }

  delete(s);
}

Symbole * Automate::PopSymbole() {
  Symbole * s = pileSymboles.back();
  pileSymboles.pop_back();
  return s;
}

void Automate::SetError() {
  error = true;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Automate::Automate(Lexer * l) : lexer(l), error(false) {
  pileEtats.push_back(new E0);
}

Automate::~Automate() {

}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées