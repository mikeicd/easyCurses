//
// Created by mike on 21/09/2021.
//

#include "easyCurses.h"

WINDOW *tela;
WINDOW *menu;
WINDOW *menuTela;


int mensagemErro(char *str) {

    mvwprintw(stdscr, 0, 0, str);
    getch();

    int yA, xA;                     // to store where you are
    getyx(stdscr, yA, xA);          // save current pos
    move(0, 0);               // move to begining of line
    clrtoeol();                     // clear line
    move(yA, xA);                   // move back to where you were

    return 0;
}


int verificaPosTela(int x, int y) {

    int yB, xB, yM, xM;
    getmaxyx(tela, yM, xM);
    getbegyx(tela, yB, xB);
    move(0, 0);

    if (y < 0 || y >= yM - 2 || x < 0 || x >= xM - 2) {
        mensagemErro("Erro ao adicionar/Remover um caractere. Posicao invalida");
        return 1;
    }
    return 0;

}

int criarTela(int linhas, int colunas) {
    int yM, xM;
    getmaxyx(stdscr, yM, xM);

    if (linhas > 0.70 * yM || colunas > xM || linhas < 1 || colunas < 1) {
        mvwprintw(stdscr, 0, 0,
                  "Erro ao criar uma tela. Nao foi possivel criar a tela devido ao tamanho do terminal, tente maximizar o terminal.\nAperte quaquer tecla para sair.");
        getch();
        endwin();
        exit(EXIT_FAILURE);
    }

    tela = newwin(linhas + 2, colunas + 2, 2, (xM - colunas + 2) / 2);
    refresh();

    box(tela, 0, 0);
    wrefresh(tela);

    return 0;
}

int adicionaChar(int x, int y, char add) {

    if (verificaPosTela(x, y) == 1) return 1;
    mvwaddch(tela, y + 1, x + 1, add);
    wrefresh(tela);
    refresh();
    return 0;

}

int removeChar(int x, int y) {

    if (verificaPosTela(x, y) == 1) return 1;
    mvwaddch(tela, y + 1, x + 1, ' ');
    wrefresh(tela);
    refresh();
    return 0;

}

int adicionaMatriz(int x, int y, char matriz[x][y]) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            adicionaChar(i, j, matriz[i][j]);
        }
    }
    return 0;
}

int criarMenuTela(int numOpcoes, int numCaracteres, char opcoes[numOpcoes][numCaracteres]) {
    int yM, xM, escolha, selecionado = 0;
    getmaxyx(stdscr, yM, xM);


    menuTela = newwin((int) (yM * 0.25), (int) (xM * 0.7), (int) (yM * 0.75) + 1, (xM - (int) (xM * 0.7)) / 2);

    refresh();
    keypad(menuTela, TRUE);
    move(0, 0);
    box(menuTela, 0, 0);


    while (1) {
        for (int i = 0; i < numOpcoes; ++i) {
            if (selecionado == i)
                wattron(menuTela, A_REVERSE);
            mvwprintw(menuTela, i + 1, 1, opcoes[i]);
            wattroff(menuTela, A_REVERSE);
        }
        wrefresh(menuTela);

        escolha = wgetch(menuTela);
        switch (escolha) {
            case KEY_UP:
                selecionado--;
                if (selecionado == -1)
                    selecionado = numOpcoes - 1;
                break;
            case KEY_DOWN:
                selecionado++;
                if (selecionado == numOpcoes)
                    selecionado = 0;
                break;
            case 'x':
                move(getbegy(menuTela), 0);
                clrtobot();
                return -1;
            case 10:
                move(getbegy(menuTela), 0);
                clrtobot();
                return selecionado;
            default:
                break;
        }
    }
}

int criarMenu(int numOpcoes, int numCaracteres, char *titulo, char opcoes[numOpcoes][numCaracteres]) {
    int yM, xM, escolha, selecionado = 0;
    getmaxyx(stdscr, yM, xM);

    menu = newwin(yM, xM, 0, 0);

    refresh();
    keypad(menu, TRUE);

    box(menu, 0, 0);
    mvwprintw(menu, 0, 3, titulo);

    while (1) {
        for (int i = 0; i < numOpcoes; ++i) {
            if (selecionado == i)
                wattron(menu, A_REVERSE);
            mvwprintw(menu, i + 1, 1, opcoes[i]);
            wattroff(menu, A_REVERSE);
        }
        wrefresh(menu);

        escolha = wgetch(menu);
        switch (escolha) {
            case KEY_UP:
                selecionado--;
                if (selecionado == -1)
                    selecionado = numOpcoes - 1;
                break;
            case KEY_DOWN:
                selecionado++;
                if (selecionado == numOpcoes)
                    selecionado = 0;
                break;
            case 'x':
                clear();
                return -1;
            case 10:
                clear();
                return selecionado;
            default:
                break;
        }
    }
}

