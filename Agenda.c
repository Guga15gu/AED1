#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void* buscar(){

    int* count;
	count = (void*)pBuffer + sizeof(int) * 3 ;

    struct pessoa * campo;
	campo = (void *)pBuffer + sizeof(int) * *i;

    int *a;
    a = (void*)pBuffer + sizeof(int) * 4 ;

    void *item;
    item = (void*)pBuffer + sizeof(int) * 5;

//Só falta modificar o código para buscar pelo nome...
    printf("Por qual campo você deseja buscar? \n1 nome; \n2 idade; \n3 telefone.\n");
    scanf("%d", a);
    int * itemi;                //precisei fazer essas gambiarras pro compilador resolver cumprir sua função
    char * itemc;               //precisei fazer essas gambiarras pro compilador resolver cumprir sua função*
    if(*a==1){
            itemc = item;       //precisei fazer essas gambiarras pro compilador resolver cumprir sua função**

            printf("Digite o nome a ser buscado: \n");
            scanf("%s", itemc); 
    }
    else if(*a==2){
            itemi = item;       //precisei fazer essas gambiarras pro compilador resolver cumprir sua função***

            printf("Digite a idade a ser buscada: \n");
            scanf("%d", itemi); 
    }
    else {
            itemi = item;       //precisei fazer essas gambiarras pro compilador resolver cumprir sua função****

            printf("Digite o telefone a ser buscado: \n");
            scanf("%d", itemi);
    }

    for(*count = 0; *count< *s; ++*count){

	    if(*a==1){

            if(itemc == campo->nome){

                printf("\nNome: %s\n", campo->nome);
		        printf("Idade: %d\n", campo->idade );
	        	printf("Telefone: %d\n\n", campo->telefone );
                return *count;
            }
        }

        else if(*a==2){
            
            if(*itemi == campo->idade ){
                
                printf("\nNome: %s\n", campo->nome);
		        printf("Idade: %d\n", campo->idade );
	        	printf("Telefone: %d\n\n", campo->telefone );
                return *count;
            }
        }
        else {
            
            if(*itemi == campo->telefone){

                printf("\nNome: %s\n", campo->nome);
		        printf("Idade: %d\n", campo->idade );
	        	printf("Telefone: %d\n\n", campo->telefone );
                return *count;
            }
        }
        
		campo = (void *)campo + sizeof(struct pessoa);
        
	}
    printf("\nContato inexistente.\n\n");
	
    return -1;
}

void apagar(void){

    struct pessoa * campo;
    int* count;
	count = (void*)pBuffer + sizeof(int) * 3 ;

    *count = buscar();
    campo = (void *)pBuffer + sizeof(int) * *i + sizeof(struct pessoa) * *count;
    
    if(*count == -1){
        printf("\nContato inexistente.\n\n");
    }

    else{

        printf("\nExcluindo contato acima...\n");
        *s = *s - 1;
        struct pessoa * aux;
        aux = campo + 1;
        for(; *count< *s; ++*count){

            strcpy(campo->nome, aux->nome);
            campo->idade = aux->idade;
            campo->telefone = aux->telefone;
            
		    campo = (void *)campo + sizeof(struct pessoa);
            aux = (void *)aux + sizeof(struct pessoa);
	    }
        realocar();
        printf("\n Sucesso na exclusão;\n");
    }
    
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
		printf("Telefone: %d\n", campo->telefone );
		campo = (void *)campo + sizeof(struct pessoa);

	}
    printf("\n");
}

int main()
{
  int *menu;

  pBuffer = malloc(sizeof(6 * sizeof(int)));

  if(pBuffer==NULL){
      printf("Erro na alocação.\n\n");
      exit(1);
  }

  i = pBuffer;
  s = i + 1;
  *i = 6;
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

			apagar();
			break;

		case 3:

            buscar();
			break;

		case 4:

			listar();
			break;


	}

	printf("Você deseja: \n 1: Adicionar uma pessoa.\n 2: Excluir uma pessoa.\n 3: Buscar uma pessoa.\n 4: Listar.\n 5: sair\n ");
	menu = (void*) pBuffer +  2 * sizeof(int);
    scanf("%d", menu);
   }

    if(*menu == 5){
        free(pBuffer);
        printf("\nFree executado.\n");
    }
    return 0;
}
