//
// Created by mike on 21/09/2021.
//

#ifndef NCURSES_EASYCURSES_H
#define NCURSES_EASYCURSES_H

#define MAX_SIZE 100

#include <errno.h>
#include <ncurses.h>
#include <stdlib.h>


extern int criarTela(int linhas, int colunas);
extern int adicionaChar(int x, int y, char add);
extern int removeChar(int x, int y);
extern int adicionaMatriz(int linhas, int colunas,char matriz[linhas][colunas]);


#endif //NCURSES_EASYCURSES_H