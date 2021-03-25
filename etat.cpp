/*************************************************************************
                           Etat  -  Implementation
                             -------------------
    début                : 23/02/2021
    copyright            : (C) 2021 par Killian OECHSLIN et Thomas MIGNOT
*************************************************************************/

//---------- Réalisation de la classe <Etat> (fichier etat.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;
//------------------------------------------------------ Include personnel
#include "Expr.h"
#include "etat.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Etat::Afficher() const {
    cout << name << endl;
}

void Etat::AfficherErreur(Automate & automate, Symbole * s, string etat, string grammaireAutorisee) {
    cout << "Erreur dans l'état " << etat << " : " << endl;
    cout << "" << automate.GetLexer()->GetFlux() << "\n";

    int iMax = *s == FIN || *s == ERREUR ? automate.GetLexer()->GetTete() : automate.GetLexer()->GetTete() - 1;

    for (int i = 0; i < iMax; i++) {
        cout << " ";
    }

    cout << "^\n";

    if (*s == ERREUR) {
        cout << "Symbole '" << automate.GetLexer()->GetFlux()[iMax] << "' non reconnu." << endl;
    } else if (*s == FIN) {
        cout << "Symbole 'FIN' inattendu." << endl;
    } else {
        cout << "Symbole '" << automate.GetLexer()->GetFlux()[iMax] << "' inattendu." << endl;
    }

    cout << "Symboles attendus : " << grammaireAutorisee << endl;
}

//---------- Réalisation de la classe <E0> (fichier etat.cpp) ------------
bool E0::Transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case INT:
            automate.Decalage(s, new E3);
            break;
        case OPENPAR:
            automate.Decalage(s, new E2);
            break;
        case EXPR:
            automate.Decalage(s, new E1);
            break;
        default:
            automate.SetError();
            this->AfficherErreur(automate, s, "E0", "INT, (");
            return true;
    }
    return false;
}

//---------- Réalisation de la classe <E1> (fichier etat.cpp) ------------
bool E1::Transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case PLUS:
            automate.Decalage(s, new E4);
            break;
        case MULT:
            automate.Decalage(s, new E5);
            break;
        case FIN:
            return true; // Accepter
            break;
        default:
            automate.SetError();
            this->AfficherErreur(automate, s, "E1", "+, *, FIN");
            return true;
    }
    return false;
}

//---------- Réalisation de la classe <E2> (fichier etat.cpp) ------------
bool E2::Transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case INT:
            automate.Decalage(s, new E3);
            break;
        case OPENPAR:
            automate.Decalage(s, new E2);
            break;
        case EXPR:
            automate.Decalage(s, new E6);
            break;
        default:
            automate.SetError();
            this->AfficherErreur(automate, s, "E2", "INT, (");
            return true;
    }
    return false;
}

//---------- Réalisation de la classe <E3> (fichier etat.cpp) ------------
bool E3::Transition(Automate & automate, Symbole * s) {
    Entier * entier;
    switch (*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            entier = (Entier *)automate.PopSymbole();
            automate.Reduction(1, new Expr(entier->GetValeur()));
            automate.AjouterNode(new Node(to_string(entier->GetValeur())));
            delete (entier);
            break;
        default:
            automate.SetError();
            this->AfficherErreur(automate, s, "E3", "+, *, ), FIN");
            return true;
    }
    return false;
}

//---------- Réalisation de la classe <E4> (fichier etat.cpp) ------------
bool E4::Transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case INT:
            automate.Decalage(s, new E3);
            break;
        case OPENPAR:
            automate.Decalage(s, new E2);
            break;
        case EXPR:
            automate.Decalage(s, new E7);
            break;
        default:
            automate.SetError();
            this->AfficherErreur(automate, s, "E4", "INT, (");
            return true;
    }
    return false;
}

//---------- Réalisation de la classe <E5> (fichier etat.cpp) ------------
bool E5::Transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case INT:
            automate.Decalage(s, new E3);
            break;
        case OPENPAR:
            automate.Decalage(s, new E2);
            break;
        case EXPR:
            automate.Decalage(s, new E8);
            break;
        default:
            automate.SetError();
            this->AfficherErreur(automate, s, "E5", "INT, (");
            return true;
    }
    return false;
}

//---------- Réalisation de la classe <E6> (fichier etat.cpp) ------------
bool E6::Transition(Automate & automate, Symbole * s) {
    switch (*s) {
        case PLUS:
            automate.Decalage(s, new E4);
            break;
        case MULT:
            automate.Decalage(s, new E5);
            break;
        case CLOSEPAR:
            automate.Decalage(s, new E9);
            break;
        default:
            automate.SetError();
            this->AfficherErreur(automate, s, "E6", "+, *, )");
            return true;
    }
    return false;
}

//---------- Réalisation de la classe <E7> (fichier etat.cpp) ------------
bool E7::Transition(Automate & automate, Symbole * s) {
    Expr * expr1;
    Expr * expr2;
    Node * noeud1;
    Node * noeud2;
    switch (*s) {
        case PLUS:
        case CLOSEPAR:
        case FIN:
            expr1 = (Expr *)automate.PopSymbole();
            delete (automate.PopSymbole()); // On enlève le '+'
            expr2 = (Expr *)automate.PopSymbole();
            automate.Reduction(3, new Expr(expr1->GetValeur() + expr2->GetValeur()));
            noeud2 = automate.PopNode();
            noeud1 = automate.PopNode();
            automate.AjouterNode(new Node("Expr", noeud1, new Node("+"), noeud2));
            delete (expr1);
            delete (expr2);
            break;
        case MULT:
            automate.Decalage(s, new E5);
            break;
        default:
            automate.SetError();
            this->AfficherErreur(automate, s, "E7", "+, *, ), FIN");
            return true;
    }
    return false;
}

//---------- Réalisation de la classe <E8> (fichier etat.cpp) ------------
bool E8::Transition(Automate & automate, Symbole * s) {
    Expr * expr1;
    Expr * expr2;
    Node * noeud1;
    Node * noeud2;
    switch (*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            expr1 = (Expr *)automate.PopSymbole();
            delete (automate.PopSymbole()); // On enlève le '*'
            expr2 = (Expr *)automate.PopSymbole();
            automate.Reduction(3, new Expr(expr1->GetValeur() * expr2->GetValeur()));
            noeud2 = automate.PopNode();
            noeud1 = automate.PopNode();
            automate.AjouterNode(new Node("Expr", noeud1, new Node("*"), noeud2));
            delete (expr1);
            delete (expr2);
            break;
        default:
            automate.SetError();
            this->AfficherErreur(automate, s, "E8", "+, *, ), FIN");
            return true;
    }
    return false;
}

//---------- Réalisation de la classe <E9> (fichier etat.cpp) ------------
bool E9::Transition(Automate & automate, Symbole * s) {
    Expr * expr;
    switch (*s) {
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
            delete (automate.PopSymbole()); // On enlève ')'
            expr = (Expr *)automate.PopSymbole();
            delete (automate.PopSymbole()); // On enlève '('
            automate.Reduction(3, expr);
            break;
        default:
            automate.SetError();
            this->AfficherErreur(automate, s, "E9", "+, *, ), FIN");
            return true;
    }
    return false;
}