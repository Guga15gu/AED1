#include <stdio.h>
#include <stdlib.h>

void *pBuffer;
int *i,*s;

struct pessoa{

    char nome[20];
    int idade;
    int telefone;

} pessoa;

void realocar(void){

    pBuffer = (void*) realloc( pBuffer, *i * sizeof(int) + *s * sizeof(struct pessoa));

    if(pBuffer==NULL){
        printf("Erro na alocação.\n\n");
        exit(1);
    }

    i = pBuffer;
    s = i + 1;

}

void corrigir(void){

//	int *z = pBuffer;

//	z = z + sizeof(int) * *i;

//	memmove()




}

void adicionar(void){

    struct pessoa *pessoa1;
 	++*s;
    realocar();

    i = pBuffer;
    s = i + 1;
    pessoa1 =  (void *)pBuffer + (*i)* sizeof(int) + sizeof(struct pessoa) * (*s-1);

    printf("Digite o nome desejado: \n");
    scanf("%s", pessoa1->nome);

    printf("Digite a idade de %s: \n", pessoa1->nome);
    scanf("%d", &pessoa1->idade);


    printf("Digite o número de telefone de %s: \n", pessoa1->nome);
    scanf("%d", &pessoa1->telefone);


}

void listar(void){

	int* count;
	count = (void*)pBuffer + sizeof(int) * 3 ;

	struct pessoa * campo;
	campo = (void *)pBuffer + sizeof(int) * *i;

	for(*count = 0; *count< *s; ++*count){
		printf("\n");
		printf( "Nome: %s\n", campo->nome );
		printf("Idade: %d\n", campo->idade );
		printf("Telefone: %d\n\n\n", campo->telefone );
		campo = (void *)campo + sizeof(struct pessoa);


	}

}

int main()
{
  int *menu;

  pBuffer = malloc(sizeof(4 * sizeof(int)));

  if(pBuffer==NULL){
      printf("Erro na alocação.\n\n");
      exit(1);
  }

  i = pBuffer;
  s = i + 1;
  *i = 4;
  *s = 0;

  menu = (void*) pBuffer + 2 * sizeof(int);

  printf("\nVocê deseja: \n 1: Adicionar uma pessoa.\n 2: Excluir uma pessoa.\n 3: Buscar uma pessoa.\n 4: Listar.\n 5: sair\n ");
  scanf("%d", menu);

  while(*menu != 5){

	switch (*menu){

		case 1:

			adicionar();

			break;

		case 2:

			//apagar(pBuffer, i, s);

			break;

		case 3:

			break;

		case 4:

			listar();
			break;


	}
	printf("Você deseja: \n 1: Adicionar uma pessoa.\n 2: Excluir uma pessoa.\n 3: Buscar uma pessoa.\n 4: Listar.\n 5: sair\n ");
	menu = (void*) pBuffer +  2 * sizeof(int);
    scanf("%d", menu);
   }

    return 0;
}
