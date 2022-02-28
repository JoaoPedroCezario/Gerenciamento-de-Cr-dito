#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

FILE *arquivo;

int deseja, busca, principal, retorno;
char sx[2] = "0", sy[2] = "1";
float aux1, aux2, aux3;

struct ag
{
	char num[4], info[2], obs[30];
	float valor;
};

struct ag sistema;

int main()
{
	arquivo = fopen("banco.txt","a+");
	fclose(arquivo);
	
	do{
	
	system ("cls");
	
	printf ("\nBANCO S.A. - V: 1.3.0 - 2017\nVoce Deseja:\n\n");
	printf ("[1] - Novo Vale\n[2] - Informacoes De Um Vale\n[3] - Sacar\n[0] - Sair\n\n");
	cin>>deseja;
	system ("cls");
	
	if (deseja == 0)
	{
		system ("pause");
		return 0;
	}
	
	if (deseja == 1)
	{
		printf ("\nNOVO VALE\n\n");
		arquivo = fopen("banco.txt","a+");
		
		printf ("Digite o No: ");
		cin>>sistema.num;
		printf ("\nDigite o Valor: ");
		cin>>sistema.valor;
		printf ("\nDigite 0: ");
		cin>>sistema.info;
		printf ("\nDigite Observacoes: ");
		cin>>sistema.obs;
		
		fwrite(&sistema, sizeof(struct ag), 1, arquivo);
		printf ("\n\nGravado!!!\n\n");
		system ("pause");
		fclose (arquivo);
		principal = 1;
	}
	
	else if (deseja == 2)
	{
		printf ("\nINFORMACOES DE UM VALE\n\n");
		arquivo = fopen ("banco.txt","r+");
		
		printf ("Digite o No: ");
		cin>>busca;
		busca = busca - 1;
		fseek(arquivo,busca*sizeof(struct ag),SEEK_SET);
		fread(&sistema, sizeof(struct ag), 1, arquivo);
		
		cout<<"\n\nNo Do Vale:........ "<<sistema.num;
		cout<<"\nValor:............. "<<sistema.valor;
		
		retorno = strcmp (sistema.info, sx); 
		if (retorno == 0) printf ("\nSacado?............ Nao");
		
		retorno = strcmp (sistema.info, sy);
		if (retorno == 0) printf ("\nSacado?............ Sim");
		
		cout<<"\nObservacoes:....... "<<sistema.obs;
		cout<<"\n\n";
		system ("pause");
		fclose (arquivo);
		principal = 1;
	}
	
	else if (deseja == 3)
	{
		printf ("\nSACAR UM VALE\n\n");
		arquivo = fopen("banco.txt","r+");
		
		printf ("Digite o No: ");
		cin>>busca;
		busca = busca - 1;
		fseek(arquivo,busca*sizeof(struct ag),SEEK_SET);
		fread(&sistema, sizeof(struct ag), 1, arquivo);
		
		cout<<"\n\nNo Do Vale:........ "<<sistema.num;
		cout<<"\nValor:............. "<<sistema.valor;
		
		retorno = strcmp (sistema.info, sx); 
		if (retorno == 0) printf ("\nSacado?............ Nao");
		
		retorno = strcmp (sistema.info, sy);
		if (retorno == 0) printf ("\nSacado?............ Sim");
		
		cout<<"\nObservacoes:....... "<<sistema.obs;
		cout<<"\n\n";
		
		printf ("Deseja Sacar(0=N;1=S)??? ");
		cin>>deseja;
		
		if (deseja == 0)
		{
			principal = 1;
		}
		
		else if (deseja == 1)
		{
			printf ("\nDigite 1: ");
			cin>>sistema.info;
			//sistema.info = "1";
			printf ("\nObservacoes: ");
			cin>>sistema.obs;
			
			fseek(arquivo,busca*sizeof(struct ag),SEEK_SET);
			fwrite(&sistema, sizeof(struct ag), 1, arquivo);
			printf ("\n\nGravado!!!\n\n");
			system ("pause");
			fclose (arquivo);
			principal = 1;
		}
	}
	
	
	}while (principal == 1);
}
