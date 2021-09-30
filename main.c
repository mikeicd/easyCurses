#include "easyCurses.h"
#include <ncurses.h>

int main() {

    initscr();
    cbreak();
    noecho();
    /*
    criarTela(5,5);

    adicionaChar(0,0,'$');
    adicionaChar(1,1,'$');
    adicionaChar(2,2,'$');
    adicionaChar(3,3,'$');
    adicionaChar(4,4,'$');
    adicionaChar(19,9,'$');

    char ma[5][5] = {
            '@', '*', '*', '*', '*',
            '*', '@', '*', '*', '*',
            '*', '*', '@', '*', '*',
            '*', '*', '*', '@', '*',
            '*', '*', '*', '*', '@'
    };

    adicionaMatriz(5,5,ma);

    getch();

    removeChar(2,1);
     */
    getch();

    char options[5][10] = {"Hello", "World", "Black", "White", "Sair"};

    //criarMenuTela(2,10,options);
    printw("%d\n", criarMenu(5, 10, "God", options));
    refresh();


    getch();
    endwin();
    return 0;
}
