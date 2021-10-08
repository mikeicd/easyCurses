# easyCurses

O easyCurses foi desenvolvido para facilitar a criação de menus gráficos utilizando-se da biblioteca NCurses.

**Ela funciona somente em Sistemas Linux e deve ter o ncurses instalado.**

**Ao se utilizar o ncurses não é possivel debugar o programa utilizando o CLion.**

**Não funciona executando(Run/Play) no CLion, porém é possivel utilizar o terminal do CLion**

### Por enquanto ele possui 5 funções:

### **int criarTela(int linhas, int colunas)**

A função criarTela() é utilizada para iniciar uma tela na idéia de simular uma tabuleiro, no terminal com as dimensões
passadas como parametro, sendo elas linhas e colunas.

### **int adicionaChar(int x, int y, char add);**

A função adicionaChar() é utilizada para adicionar um caractere na tela criada. Nos parametros passados temos em ordem:
a posição X, Y e o caractere que será adicionado.

### **int removeChar(int x, int y);**

A função removeChar() é similar ao adicionaChar(), onde ela adiciona um espaço em branco (' ')
nas coordenadas passadas por parametros.

### **int adicionaMatriz(int linhas, int colunas,char matriz[linhas][colunas])**;

Seu objetivo é facilitar a tarefa de adicionar varios caracteres de uma vez só. Os parametros passados a ela são as
dimensões da matriz e a pŕopria matriz.

### **int criarMenuTela(int numOpcoes, int numCaracteres, char opcoes[numOpcoes][numCaracteres]);**

Podemos utilizar a função criarMenuTela() para adicionar um menu abaixo da tela. As opções do menu serão passados por
parametro sendo eles as dimensões do vetor de strings e o proprio vetor.

Quando essa função é iniciada a navegação é controlada pelas setas do teclado e ao apertar enter a função retornará um
inteiro que é a posição do vetor da opção selecionada.
