# LALR Parser

LALR Parser made in C++ at INSA Lyon (4th year) by Killian OECHSLIN and Thomas MIGNOT.

# Makefile

## Compilation

`make parser` or just `make`

## Get help

`make help`

## Remove .o files and executable

`make clean`

# How to use ?

Syntax (on Linux) : `./parser [-t] EXPRESSION`

Our parser will parse the expression, evaluate it and display the final result. To avoid any troubles you can surround the expression with quotes.

The authorized grammar is : + \* ( ) INT

Besides, if you use the option `-t` it will generate a file called 'arbre.png' which is the representation of the syntax tree of the expression, built with Graphviz (so you must install Graphviz first).
