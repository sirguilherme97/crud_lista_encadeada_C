#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "crud.h"
#include <string.h>

int main (int argc, char* argv[]){
	setlocale (0,"");
	Lista lista;
	int id,op;
	int flagCad = 0;
	iniciar(&lista);
	backup(&lista);
	do{
		system ("cls");
		printf ("\n [1] Cadastrar  ");
		printf ("\n [2] Imprimir");
		printf ("\n [3] Editar");
		printf ("\n [4] Excluir");
		printf ("\n\n [0] Salvar");
		printf ("\n\n Opção: ");
		scanf ("%d",&op);
		switch(op){
			case 1:{
				cadastrar(&lista);
				flagCad = 1;
				break;
			}
			case 2:{
				imprimir(&lista);
				printf (" Digite qualquer tecla para continuar ... ");
				getchar();
				getchar();
				break;
			}
			case 3:{
				system ("cls");
				printf ("\n Edição de Cliente\n");
				printf ("\n Digite o ID do cliente que deseja editar: ");
				scanf ("%d",&id);
				editar(&lista, id);
				break;
			}
			case 4:{
				system ("cls");
				printf ("\n Exclusão de Cliente\n");
				printf ("\n Digite o ID do cliente que deseja excluir: ");
				scanf ("%d",&id);
				excluir(&lista, id);
				break;
			}
			case 0:{
				system ("cls");
				if(flagCad==1){
					salvar(&lista);
					printf ("\n Salvando ...\n Cadastros Salvos\n Saindo ...");
				}else{
					printf ("\n Salvando ...\n Saindo ...");
				}
				break;
			}
			default:{
				printf ("\n Opção inválida");
			}
		}
	}while(op!=0);
	return 0;
}
