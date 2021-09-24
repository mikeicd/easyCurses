//
// Created by mike on 24/09/2021.
//
#include "easyCurses.h"
#include <ncurses.h>



int main() {
    initscr();              // inicia a tela do ncurses
    cbreak();               // Fecha aplicação como se fosse no terminal instantaneo
    //raw();                // Fecha aplicação mais espera apertar enter ou outra tecla
    noecho();               // não mostra teclas apertadas durante execução

    int y,x,yB,xB,yM,xM;


    WINDOW *win = newwin(10, 20 , 2, 2 );       //Cria tela com os parametros passados, assim como o move, Y vem primeiro


    getyx(stdscr, y ,x);    //Pega posicao xy da tela
    getbegyx(win,yB,xB);    //Pega posicao init da tela
    getmaxyx(stdscr,yM,xM); //Pega posicao max da tela

    refresh();

    //wmove(win, 1,1);
    //wprintw(win,"Hey!");
    mvwprintw(win,1,1,"Hey");           //Move e printa na janela passada como parametro
    box(win, (int)'#',0);         //Cria uma caixa na tela passado como parametro, v = vertical char, h= horizontal char
    wrefresh(win);                      //Atualiza uma determinada tela.


    //move(5,5);                    //move o ponteiro ou cursor aonde é printado os itens na tela
    //printw("Ola amiguinhos");     //Printa na tela a string passada como parametro
    // move(10,0);
    // clear();                     // Limpa tela
    //printw("%d", c);              //print w é similar ao printf

    refresh();          // atualiza a tela
    getch();
    endwin();           //encerra o ncurses e desaloca memoria

    return 0;
}