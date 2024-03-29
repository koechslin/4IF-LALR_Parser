/*************************************************************************
                           Lexer  -  Implementation
                             -------------------
    début                : 23/02/2021
    copyright            : (C) 2021 par Killian OECHSLIN et Thomas MIGNOT
*************************************************************************/

//---------- Réalisation de la classe <Lexer> (fichier lexer.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "lexer.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Symbole * Lexer::Consulter() {
    if (!tampon) {

        if (tete == (int)flux.length())
            tampon = new Symbole(FIN);
        else {

            switch (flux[tete]) {
                case '(':
                    tampon = new Symbole(OPENPAR);
                    tete++;
                    break;
                case ')':
                    tampon = new Symbole(CLOSEPAR);
                    tete++;
                    break;
                case '*':
                    tampon = new Symbole(MULT);
                    tete++;
                    break;
                case '+':
                    tampon = new Symbole(PLUS);
                    tete++;
                    break;
                default:
                    if (flux[tete] <= '9' && flux[tete] >= '0') {
                        int resultat = flux[tete] - '0';
                        int i = 1;
                        while (flux[tete + i] <= '9' && flux[tete + i] >= '0') {
                            resultat = resultat * 10 + (flux[tete + i] - '0');
                            i++;
                        }
                        tete = tete + i;
                        tampon = new Entier(resultat);
                    } else {
                        tampon = new Symbole(ERREUR);
                    }
            }
        }
    }
    return tampon;
}

void Lexer::Avancer() {
    tampon = nullptr;
}

string Lexer::GetFlux() {
    return this->flux;
}

int Lexer::GetTete() {
    return this->tete;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées