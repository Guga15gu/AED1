#include <stdio.h>
#include <stdlib.h>

struct pessoa{

    char nome[20];
    int idade;
    char telefone[20];

} pessoa;

void realocar(int *pBuffer, int *i, int *s){
	++*s;
    pBuffer = realloc( pBuffer, *i * sizeof(int) + *s * sizeof(struct pessoa));

    i = pBuffer;
    s = i + 1;
    
}

void adicionar(int *pBuffer, int *i, int *s){

    struct pessoa *pessoa1;
 
    realocar(pBuffer, i, s);

    i = pBuffer;
    s = i + 1;
    pessoa1 = s + 1;

    printf("Digite o nome desejado: \n");
    scanf("%s", pessoa1->nome);
    	
    printf("Digite a idade de %s: \n", pessoa1->nome);
    scanf("%d", &pessoa1->idade);
    
    printf("Digite o número de telefone de %s: \n", pessoa1->nome);
    scanf("%s", pessoa1->telefone);
}

void listar(int *pBuffer, int *i, int *s){
	
	//for(){}
  
}

int main()
{
  void *pBuffer;
  int *i, *s;

  pBuffer = malloc(sizeof(3 * sizeof(int)));
  i = pBuffer;
  s = i + 1;
  *i = 3;
  *s = 0;

  int *menu;
  ++*i;
  realocar(pBuffer, i, s);

  menu = pBuffer + ((*i - 1) * sizeof(int));

  printf("Você deseja: \n 1: Adicionar uma pessoa.\n 2: Excluir uma pessoa.\n 3: Buscar uma pessoa.\n 4: Listar.\n 5: sair\n ");
  scanf("%d", menu);

  while(*menu != 5){
	  
	switch (*menu){
	
		case 1:
	
			adicionar(pBuffer, i, s);

			break;

		case 2:
		
			//apagar(pBuffer, i, s);
		
			break;

		case 3:

			break;

		case 4:
			
			listar(pBuffer, i, s);
			break;
		

	}
	printf("Você deseja: \n 1: Adicionar uma pessoa.\n 2: Excluir uma pessoa.\n 3: Buscar uma pessoa.\n 4: Listar.\n 5: sair\n ");
    scanf("%d", menu);
   }

    return 0;
}
