#include <iostream>
#include "lexer.h"
#include "automate.h"

int main(void) {
   string chaine("123+234*2+(12*(3+4))");

   Lexer l(chaine);

   Automate a(&l);

   a.Lecture();

   return 0;
}

