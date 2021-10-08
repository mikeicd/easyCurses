#include "easyCurses.h"
#include <ncurses.h>

int main() {

    initscr();
    cbreak();
    noecho();


    /*
     * A função criarTela() é utilizada para iniciar uma tela na idéia de simular uma tabuleiro,
     * no terminal com as dimensões passadas como parametro, sendo elas linhas e colunas.
     */
    criarTela(5, 5);


    /*
     * A função adicionaChar() é utilizada para adicionar um caractere na tela criada.
     * Nos parametros passados temos em ordem: a posição X, Y e o caractere que será adicionado.
     */
    adicionaChar(0, 0, '$');
    adicionaChar(1, 1, '$');
    adicionaChar(2, 2, '$');
    adicionaChar(3, 3, '$');
    adicionaChar(4, 4, '$');
    adicionaChar(19, 9, '$');


    /*
     * Aqui segue um exemplo de como se declarar uma matriz para se utilizar
     * com a função adicionaMatriz()
     */
    char ma[5][5] = {
            '@', '*', '*', '*', '*',
            '*', '@', '*', '*', '*',
            '*', '*', '@', '*', '*',
            '*', '*', '*', '@', '*',
            '*', '*', '*', '*', '@'
    };

    /*
     * Temos então a função adicionaMatriz(), na qual tem seu objetivo facilitar a tarefa
     * de adicionar varios caracteres de uma vez só. Os parametros passados a ela são as
     * dimensões da matriz e a pŕopria matriz.
     *
     * O preenchimento dela será iniciado no canto superior esquerdo da tela e como a matriz
     * possui suas proprias dimensões tem que tomar cuidado com o tamanho da tela, onde pode
     * ocorrer casos de caracteres ter coordenadas invalida ou não preencher toda a tela.
     */
    adicionaMatriz(5, 5, ma);

    /*
     * A função getch() pode ser utilizada para fazer uma pausa do programa, ela é utilizada
     * em algumas funções para mostrar mensagens de erro e aguarda o usuário que pressione uma
     * tecla para continuar o processo.
     */
    getch();

    /*
     * A função removeChar() é similar ao adicionaChar(), onde ela adiciona um espaço em branco ' '
     * nas coordenadas passadas por parametros.
     */
    removeChar(2, 1);

    getch();


    /*
     * Exemplo de como declarar um vetor de strings, onde nas dimensões podemos considerar
     * 5 palavras de até 10 caracteres.
     */
    char options[5][10] = {"Hello", "World", "Black", "White", "Sair"};

    /*
     * Podemos utilizar a função criarMenuTela() para adicionar um menu abaixo da tela.
     * As opções do menu serão passados por parametro sendo eles as dimensões do vetor
     * de strings e o proprio vetor.
     *
     * Quando essa função é iniciada a navegação é controlada pelas setas do teclado
     * e ao apertar enter a função retornará um inteiro que é a posição do vetor da opção
     * selecionada.
     */
    criarMenuTela(5, 10, options);



    //printw("%d\n", criarMenu(5, 10, "Menu", options));
    refresh();


    getch();
    endwin();
    return 0;
}
