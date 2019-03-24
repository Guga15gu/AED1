#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void adiciona(char **string){
	
	char nome[20];
	int tamanho;
	
	printf("Digite o nome: ");
	scanf("%s", nome);
	getchar();
	
	tamanho = strlen(nome);
	//printf("\n1e %s \n", nome);
	nome[tamanho] = '*';
	nome[tamanho+1] = '\0';
	//printf("\n1 %s \n", nome);
	//tamanho=0;
	
	if( *string == NULL ){
		
		*string = (char*)malloc( tamanho*sizeof(char) );
	
		strcpy(*string, nome);
		
		//printf("\n2 %s \n", *string);
	}
	

	else{
		
		//printf("\n else \n");
		
		int leng;
		
		leng = strlen(*string);
		
		tamanho = tamanho + leng + 1;
		
		*string = realloc( *string, tamanho * sizeof(char) );
		//printf("\n %s \n", *string);
		
		
		strcat(*string, nome);
		
		//printf("\n %s \n", *string);
		
	}
		
}

void remover(char **string){
	
	char nome[20];
	int tamanho, t;
	char *posicao;
	char *inter;
	
	printf("Digite o nome: ");
	scanf("%s", nome);
	//getchar();
	
	tamanho = strlen(nome);
	t = strlen(*string);
	
	printf("%d", t);
	
	nome[tamanho] = '*';
	
	posicao = strstr(*string, nome);
	
	if( posicao == NULL ){
		
		printf("Nome n�o localizado./n");		
	}
	
	else{
		
		inter = posicao + (tamanho*(sizeof(char))) + sizeof(char);
		
		while( *inter != '\0' ){
			
			*posicao = *inter;		
			++posicao;
			++inter;
			//printf("\n %s \n", *string);
		}
		*posicao = '\0';
		*string = realloc(*string, t - (tamanho*(sizeof(char))) );
		
		printf("\n %s \n", *string);
			
	}
}

void listar(char **string){
	
	char *letra;
	letra = *string;
	
	while(*letra != '\0'){
	
		while(*letra != '*'){
			
			printf("%c", *letra);
			
			++letra;
		
		}	
		printf("\n");
		++letra;
	}
	
}

int main(int argc, char **argv)
{
	int a;
	char *string = NULL;
	
	printf("Digite a opção desejada: \n1 para adicionar.\n2 para remover.\n3 para listar.\n4 para sair.\n");
	scanf("%d", &a);
	getchar();
	
	while(a!=4){
		
		if( a==1 ){
			
			adiciona(&string);
			
		}
		
		else if( a==2 ){
			
			remover(&string);
			
		}
		
		else if( a==3 ){
			
			listar(&string);
			
		}
		
		if( a!= 4 ){
			
			printf("Digite a opção desejada: \n1 para adicionar.\n2 para remover.\n3 para listar.\n4 para sair.\n");
			scanf("%d", &a);
			
		}
		
	}
		
	return 0;
}

