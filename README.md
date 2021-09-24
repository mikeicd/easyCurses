# easyCurses
 O easyCurses foi desenvolvido para facilitar a criação de menus gráficos utilizando-se da biblioteca NCurses.
 
 **Ela funciona somente em Sistemas Linux e deve ter o ncurses instalado.**
 
 **Quando se é utilizado o ncurses não é possivel debugar o programa utilizando o CLion.**
 
 **Não funciona no terminal do CLion**
 
 
 Por enquanto ele possui 4 funções:
 
 int criarTela(int linhas, int colunas)
 Na qual é usada para iniciar uma tela com os parametros passados que determinam sua seu tamanho, na criação é feita uma verificação do 
 tamanha maximo que o terminal suporta, então deve-se ajustar o tamanho do terminal antes de executar o programa.
 
int adicionaChar(int x, int y, char add);
Utilizado para adicionar um caractere na tela criada. É passado a posição x,y e o caractere que será inserido. 

int removeChar(int x, int y);
Utilizado para remover um caractere da posição x,y que é passada como parametro.

int adicionaMatriz(int linhas, int colunas,char matriz[linhas][colunas]);
Se utiliza de uma matriz de caracteres para adicionalos todos de uma vez a tela.
