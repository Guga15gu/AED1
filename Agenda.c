#include <stdio.h>
#include <stdlib.h>

struct pessoa{

    char nome[20];
    int idade;
    char telefone[20];

} pessoa;

void *pBuffer;
int *i, *s, *menu, *count;

void realocar(void){

    pBuffer = realloc( pBuffer, *i * sizeof(int) + *s * sizeof(struct pessoa));

    i = pBuffer;
    s = i + 1;

}

void adicionar(void){

    struct pessoa *pessoa1;
    ++*s;
    realocar();

    i = pBuffer;
    s = i + 1;
    pessoa1 = ((*i + 1) * sizeof(int));

    printf("Digite o nome desejado: \n");
    scanf("%s", pessoa1->nome);

    printf("Digite a idade de %s: \n", pessoa1->nome);
    scanf("%d", &pessoa1->idade);

    printf("Digite o número de telefone de %s: \n", pessoa1->nome);
    scanf("%s", pessoa1->telefone);
}

void listar(void){

    ++*i;
    realocar;
	count = pBuffer + (*i + 1)* sizeof(int);

    for(; *count < s){







    }



}

int main()
{


  pBuffer = malloc(sizeof(4 * sizeof(int)));
  i = pBuffer;
  s = i + 1;
  *i = 4;
  *s = 0;

  realocar();

  menu = s + 1;

  printf("Você deseja: \n 1: Adicionar uma pessoa.\n 2: Excluir uma pessoa.\n 3: Buscar uma pessoa.\n 4: Listar.\n 5: sair\n ");
  scanf("%d", menu);

  while(*menu != 5){

	switch (*menu){

		case 1:

			adicionar();

			break;

		case 2:

			//apagar();

			break;

		case 3:

			break;

		case 4:

			listar();
			break;


	}
	menu = s + 1;
	printf("Você deseja: \n 1: Adicionar uma pessoa.\n 2: Excluir uma pessoa.\n 3: Buscar uma pessoa.\n 4: Listar.\n 5: sair\n ");
    scanf("%d", menu);
   }

    return 0;
}

