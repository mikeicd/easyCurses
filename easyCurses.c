//
// Created by mike on 21/09/2021.
//

#include "easyCurses.h"

WINDOW *tela;
WINDOW *menuTela;

int mensagemErro(char *str){

    mvwprintw(stdscr,0,0,str);
    getch();

    int yA, xA;            // to store where you are
    getyx(stdscr, yA, xA); // save current pos
    move(0, 0);          // move to begining of line
    clrtoeol();          // clear line
    move(yA, xA);          // move back to where you were

    return 0;
}


int verificaPosTela(int x, int y){

    int yB,xB,yM,xM;
    getmaxyx(tela,yM,xM);
    getbegyx(tela,yB,xB);
    move(0,0);

    if (y < 0 || y >= yM-2 || x < 0 || x >= xM-2){
        mensagemErro("Erro ao adicionar/Remover um caractere. Posicao invalida");
        return 1;
    }
    return 0;

}

int criarTela(int linhas, int colunas) {
    int yM,xM;
    getmaxyx(stdscr,yM,xM);

    if (linhas > 0.70*yM || colunas > xM || linhas < 1  || colunas < 1){
        mvwprintw(stdscr,0,0,"Erro ao criar uma tela. Nao foi possivel criar a tela devido ao tamanho do terminal, tente maximizar o terminal.\nAperte quaquer tecla para sair.");
        getch();
        endwin();
        exit(EXIT_FAILURE);
    }

    tela = newwin(linhas+2, colunas+2 , 2, 2);
    refresh();

    box(tela,0,0);
    wrefresh(tela);

    return 0;
}

int adicionaChar(int x, int y, char add) {

    if (verificaPosTela(x,y) == 1) return 1;

    char c[1] = {add};

    mvwprintw(tela, y+1, x+1, c);
    wrefresh(tela);
    refresh();
    return 0;

}

int removeChar(int x,int y) {

    if (verificaPosTela(x,y) == 1) return 1;
    mvwprintw(tela, y+1, x+1, " ");
    wrefresh(tela);
    refresh();
    return 0;

}

int adicionaMatriz(int x, int y, char matriz[x][y]){
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            adicionaChar(i, j, matriz[i][j]);
        }
    }
    return 0;
}

int criarMenuTela(int numOpcoes, char opcoes[numOpcoes]){
    int yM,xM;
    getmaxyx(stdscr,yM,xM);

    menuTela = newwin((int)(yM*0.25) , (int)(xM*0.7) , (int)(yM*0.3)+1, 2);
    refresh();

    box(menuTela,0,0);
    wrefresh(tela);

    return 0;

}

