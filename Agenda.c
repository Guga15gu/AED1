#include <stdio.h>
#include <stdlib.h>

struct pessoa{

    char nome[20];
    int idade;
    int telefone;

};
void realocar(int *pBuffer, int *i, int *c, int *s){

    pBuffer = realloc( pBuffer, *i * sizeof(int) + *c * sizeof(char) + *s * sizeof(struct pessoa));

    i = pBuffer;
    c = i + 1;
    s = c + 1;
}



int main()
{
  void *pBuffer;
  int *i, *c, * s;

  pBuffer = malloc(sizeof(3 * sizeof(int)));
  i = pBuffer;
  c = i + 1;
  s = c + 1;
  *i = 3;
  *c = 0;
  *s = 0;

  int *menu;
  ++*i;
  realocar(pBuffer, i, c, s);

  menu = pBuffer + ((*i - 1) * sizeof(int));

  printf("Você deseja: \n 1: Adicionar uma pessoa.\n 2: Excluir uma pessoa.\n 3: Buscar uma pessoa.\n 4: Listar.\n 5: sair\n ");
  scanf("%d", menu);


  switch (*menu){

    case 1:

        printf("1 opção");

        break;

    case 2:

        break;

    case 3:

        break;

    case 4:

        break;

    case 5:

        break;


  }

    return 0;
}
