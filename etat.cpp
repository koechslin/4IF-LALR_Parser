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
void Etat::Afficher() const
{
    cout << name << endl;
}

//---------- Réalisation de la classe <E0> (fichier etat.cpp) ------------
bool E0::Transition(Automate &automate, Symbole *s)
{
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
        cout << "Erreur dans l'état E0 :" << endl;
        cout << "Symboles attendus : INT, OPENPAR, EXPR" << endl;
        cout << "Symbole lu : ";
        s->Affiche();
        cout << endl;
        return true;
    }
    return false;
}

//---------- Réalisation de la classe <E1> (fichier etat.cpp) ------------
bool E1::Transition(Automate &automate, Symbole *s)
{
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
        cout << "Erreur dans l'état E1 :" << endl;
        cout << "Symboles attendus : PLUS, MULT, FIN" << endl;
        cout << "Symbole lu : ";
        s->Affiche();
        cout << endl;
        return true;
    }
    return false;
}

//---------- Réalisation de la classe <E2> (fichier etat.cpp) ------------
bool E2::Transition(Automate &automate, Symbole *s)
{
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
        cout << "Erreur dans l'état E2 :" << endl;
        cout << "Symboles attendus : INT, OPENPAR, EXPR" << endl;
        cout << "Symbole lu : ";
        s->Affiche();
        cout << endl;
        return true;
    }
    return false;
}

//---------- Réalisation de la classe <E3> (fichier etat.cpp) ------------
bool E3::Transition(Automate &automate, Symbole *s)
{
    Entier *entier;
    switch (*s) {
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
        entier = (Entier *)automate.PopSymbole();
        automate.Reduction(1, new Expr(entier->GetValeur()));
        delete (entier);
        break;
    default:
        automate.SetError();
        cout << "Erreur dans l'état E3 :" << endl;
        cout << "Symboles attendus : PLUS, MULT, CLOSEPAR, FIN" << endl;
        cout << "Symbole lu : ";
        s->Affiche();
        cout << endl;
        return true;
    }
    return false;
}

//---------- Réalisation de la classe <E4> (fichier etat.cpp) ------------
bool E4::Transition(Automate &automate, Symbole *s)
{
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
        cout << "Erreur dans l'état E4 :" << endl;
        cout << "Symboles attendus : INT, OPENPAR, EXPR" << endl;
        cout << "Symbole lu : ";
        s->Affiche();
        cout << endl;
        return true;
    }
    return false;
}

//---------- Réalisation de la classe <E5> (fichier etat.cpp) ------------
bool E5::Transition(Automate &automate, Symbole *s)
{
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
        cout << "Erreur dans l'état E5 :" << endl;
        cout << "Symboles attendus : INT, OPENPAR, EXPR" << endl;
        cout << "Symbole lu : ";
        s->Affiche();
        cout << endl;
        return true;
    }
    return false;
}

//---------- Réalisation de la classe <E6> (fichier etat.cpp) ------------
bool E6::Transition(Automate &automate, Symbole *s)
{
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
        cout << "Erreur dans l'état E6 :" << endl;
        cout << "Symboles attendus : PLUS, MULT, CLOSEPAR" << endl;
        cout << "Symbole lu : ";
        s->Affiche();
        cout << endl;
        return true;
    }
    return false;
}

//---------- Réalisation de la classe <E7> (fichier etat.cpp) ------------
bool E7::Transition(Automate &automate, Symbole *s)
{
    Expr *expr1;
    Expr *expr2;
    switch (*s) {
    case PLUS:
    case CLOSEPAR:
    case FIN:
        expr1 = (Expr *)automate.PopSymbole();
        delete (automate.PopSymbole()); // On enlève le '+'
        expr2 = (Expr *)automate.PopSymbole();
        automate.Reduction(3, new Expr(expr1->GetValeur() + expr2->GetValeur()));
        delete (expr1);
        delete (expr2);
        break;
    case MULT:
        automate.Decalage(s, new E5);
        break;
    default:
        automate.SetError();
        cout << "Erreur dans l'état E7 :" << endl;
        cout << "Symboles attendus : PLUS, MULT, CLOSEPAR, FIN" << endl;
        cout << "Symbole lu : ";
        s->Affiche();
        cout << endl;
        return true;
    }
    return false;
}

//---------- Réalisation de la classe <E8> (fichier etat.cpp) ------------
bool E8::Transition(Automate &automate, Symbole *s)
{
    Expr *expr1;
    Expr *expr2;
    switch (*s) {
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
        expr1 = (Expr *)automate.PopSymbole();
        delete (automate.PopSymbole()); // On enlève le '*'
        expr2 = (Expr *)automate.PopSymbole();
        automate.Reduction(3, new Expr(expr1->GetValeur() * expr2->GetValeur()));
        delete (expr1);
        delete (expr2);
        break;
    default:
        automate.SetError();
        cout << "Erreur dans l'état E8 :" << endl;
        cout << "Symboles attendus : PLUS, MULT, CLOSEPAR, FIN" << endl;
        cout << "Symbole lu : ";
        s->Affiche();
        cout << endl;
        return true;
    }
    return false;
}

//---------- Réalisation de la classe <E9> (fichier etat.cpp) ------------
bool E9::Transition(Automate &automate, Symbole *s)
{
    Expr *expr;
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
        cout << "Erreur dans l'état E9 :" << endl;
        cout << "Symboles attendus : PLUS, MULT, CLOSEPAR, FIN" << endl;
        cout << "Symbole lu : ";
        s->Affiche();
        cout << endl;
        return true;
    }
    return false;
}