#ifndef CRUDCLIENTE_H_INCLUDED
#define CRUDCLIENTE_H_INCLUDED
#include <string.h>

typedef struct Cliente{
		int codigo;
		char nome[50];
		char empresa[50];
		char departamento[50];
		char tel[12];
		char email[50];
}Cliente;

typedef struct No {
	struct Cliente cliente;
	struct No *proximo;
}No;

typedef struct{
	No *inicio;
	No *fim;
	int tam;
}Lista;

void iniciar (Lista *lista){
	lista->inicio = NULL;
	lista->fim = NULL;
	lista->tam =  0;
}

void cadastrar(Lista *lista){
	system ("cls");
	printf ("\n Cadastro de Cliente\n");
	No *novo = (No*)malloc(sizeof(No));
	printf ("\n Digite o id do cliente: ");
	scanf (" %d",&novo->cliente.codigo);
	printf (" Digite o nome do cliente: ");
	scanf (" %[^\n]s",&novo->cliente.nome);
	printf (" Digite a empresa do Cliente: ");
	scanf (" %[^\n]s",&novo->cliente.empresa);
	printf (" Digite o departamento da empresa: ");
	scanf (" %[^\n]s",&novo->cliente.departamento);
	printf (" Digite o telefone do Cliente: ");
	scanf (" %[^\n]s",&novo->cliente.tel);
	printf (" Digite o email do Cliente: ");
	scanf (" %[^\n]s",&novo->cliente.email);
	novo->proximo = NULL;
	if(lista->inicio == NULL){
		lista->inicio = novo;
		lista->fim = novo;
	}else{
		lista->fim->proximo = novo;//encadeamento da lista
		lista->fim = novo; // mudança do fim para o novo elemento
	}
	lista->tam++;
}

void cadastrarBackUp(Lista *lista, int codigo, char* nome, char* empresa, char* setor, char* tel, char* email){
	No *novo = (No*)malloc(sizeof(No));
	novo->cliente.codigo = codigo;
	strcpy(novo->cliente.nome,nome);
	strcpy(novo->cliente.empresa,empresa);
	strcpy(novo->cliente.departamento,setor);
	strcpy(novo->cliente.tel,tel);
	strcpy(novo->cliente.email,email);
	novo->proximo = NULL;
	if(lista->inicio == NULL){
		lista->inicio = novo;
		lista->fim = novo;
	}else{
		lista->fim->proximo = novo;
		lista->fim = novo;
	}
	lista->tam++;
}

void imprimir(Lista *lista){
	system ("cls");
	printf ("\n Lista de Clientes [%d]\n",lista->tam);
	No *inicio = lista->inicio;
	while (inicio!=NULL){
		if(inicio->proximo==NULL){
			printf ("\n ID\t\t %d",inicio->cliente.codigo);
			printf ("\n Nome\t\t %s",inicio->cliente.nome);
			printf ("\n Empresa\t %s",inicio->cliente.empresa);
			printf ("\n Departamento\t %s",inicio->cliente.departamento);
			printf ("\n Telefone\t %s",inicio->cliente.tel);
			printf ("\n Email\t\t %s",inicio->cliente.email);
			printf ("\n ------------------------------------------");
			break;
		}
		printf ("\n ID\t\t %d",inicio->cliente.codigo);
		printf ("\n Nome\t\t %s",inicio->cliente.nome);
		printf ("\n Empresa\t %s",inicio->cliente.empresa);
		printf ("\n Departamento\t %s",inicio->cliente.departamento);
		printf ("\n Telefone\t %s",inicio->cliente.tel);
		printf ("\n Email\t\t %s",inicio->cliente.email);
		printf ("\n ------------------------------------------");
		inicio = inicio->proximo;
	}
	printf ("\n");
}

void editar (Lista *lista, int id){
	system ("cls");
	printf ("\n Edição de Cliente - ID [%d]\n",id);
	No *inicio = lista->inicio;
	while (inicio->cliente.codigo != id){
		inicio = inicio->proximo;
	}
	printf (" Digite o nome do cliente: ");
	scanf (" %[^\n]s",&inicio->cliente.nome);
	printf (" Digite a empresa do Cliente: ");
	scanf (" %[^\n]s",&inicio->cliente.empresa);
	printf (" Digite o departamento da empresa: ");
	scanf (" %[^\n]s",&inicio->cliente.departamento);
	printf (" Digite o telefone do Cliente: ");
	scanf (" %[^\n]s",&inicio->cliente.tel);
	printf (" Digite o email do Cliente: ");
	scanf (" %[^\n]s",&inicio->cliente.email);
}

void excluir (Lista *lista, int id){
	system ("cls");
	No *anterior, *atual;
	printf ("\n Exclusão de Cliente - ID [%d]\n",id);
	if(lista->inicio == NULL){
		printf ("\n Lista Vazia");
	}else{
		anterior = lista->inicio;
		atual = lista->inicio;
		while(atual != NULL){//encontrei o elemento
			if (atual->cliente.codigo == id){//elemento é o primeiro da lista  id){
				if(atual == lista->inicio){
					lista->inicio = lista->inicio->proximo;
					free(atual);
					lista->tam--;
					break;
				}else{                   //elemento é o ultimo da lista
					if(atual == lista->fim){
						lista->fim = anterior;
					}
					//refazendo encadeamento
					anterior->proximo = atual->proximo;
					free(atual);
					lista->tam--;
					break;
				}
			}else{//caso não encontre a posição, caminhar os ponteiros pela lista até achar o IDvalor
				anterior = atual;
				atual = atual->proximo;
			}
		}
	}
}

void salvar (Lista *lista){
	No *inicio = lista->inicio;
	FILE *file = fopen ("./clientes.json","wt");
	FILE *file2 = fopen ("./clientes.txt","wt");
	if(!file && !file2){
		printf ("\n Não foi possível salvar as informações por algum motivo =( \n Erro <00x001>\n\n");
		getchar();
	}else{
		fprintf(file,"{\n");
		while (inicio!=NULL){
			fprintf(file,"   \"p%d\":{\n",inicio->cliente.codigo);
			fprintf(file,"      \"id\":");
			fprintf(file,"%d,\n",inicio->cliente.codigo);
			fprintf(file,"      \"Nome\":");
			fprintf(file,"\"%s\",\n",inicio->cliente.nome);
			fprintf(file,"      \"Empresa\":");
			fprintf(file,"\"%s\",\n",inicio->cliente.empresa);
			fprintf(file,"      \"departamento\":");
			fprintf(file,"\"%s\",\n",inicio->cliente.departamento);
			fprintf(file,"      \"Telefone\":");
			fprintf(file,"\"%s\",\n",inicio->cliente.tel);
			fprintf(file,"      \"Email\":");
			fprintf(file,"\"%s\"\n",inicio->cliente.email);
			fprintf(file,"   },\n");
			//-----------------------------------------------
			fprintf(file2,"%d\n",inicio->cliente.codigo);
			fprintf(file2,"%s\n",inicio->cliente.nome);
			fprintf(file2,"%s\n",inicio->cliente.empresa);
			fprintf(file2,"%s\n",inicio->cliente.departamento);
			fprintf(file2,"%s\n",inicio->cliente.tel);
			fprintf(file2,"%s\n",inicio->cliente.email);
			inicio = inicio->proximo;
		}
		fprintf(file,"}");
	}
	fclose(file);
	fclose(file2);
}
void backup(Lista* lista){
	int codigo=0;
	char nome[50];
	char empresa[50];
	char departamento[50];
	char tel[50];
	char email[50];
	FILE *arquivo;
    arquivo = fopen("./clientes.txt","rt");
	
    if (arquivo){
        while(fscanf(arquivo, "% [^\n]", lista) != EOF){
//        	fgets(codigo,1,arquivo);
//        	fgets (codigo,1, arquivo);
//			fgets (nome,50, arquivo);
//			fgets (empresa,50, arquivo);
//			fgets (departamento,50, arquivo);
//			fgets (tel,50, arquivo);
//			fgets (email,50, arquivo);
            fscanf(arquivo,"%d",&codigo);
            fscanf(arquivo," %[^\n]s",&nome);
            fscanf(arquivo," %[^\n]s",&empresa);
            fscanf(arquivo," %[^\n]s",&departamento);
            fscanf(arquivo," %[^\n]s",&tel);
            fscanf(arquivo," %[^\n]s",&email);
			cadastrarBackUp(lista, codigo,nome,empresa,departamento,tel,email);
        }
    }
    fclose(arquivo);
}
#endif
