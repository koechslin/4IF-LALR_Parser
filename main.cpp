#include <iostream>
#include "lexer.h"
#include "automate.h"

int main(void) {
   string chaine("(1+2)*3+(((4+5)+6)*7)+8*9");

   Lexer l(chaine);

   Automate a(&l);

   a.Lecture();

   return 0;
}

