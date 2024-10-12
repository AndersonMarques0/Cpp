#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAX_PILHA 60

struct Item{
	int Codigo;
	string Nome;
	float Preco;
};

struct Pilha{
	Item Lista[MAX_PILHA];
	int Topo;
};

void Ini_Pilha(Pilha *P){ //Cria uma lista vazia
	P->Topo = -1;	
}

int Pilha_Vazia(Pilha *P){ //Verifica se a pilha está vazia (1 - Vazia, 0 - Tem mais de 1 elemento)
	int Ret;

	if (P->Topo == -1){
		Ret = 1;
	}
	else{
		Ret = 0;
	}
	
	return Ret;
}

int Tamanho(Pilha *P){
	
	return P->Topo + 1;
}

int Pilha_Cheia(Pilha *P){ //Verifica se a lista está vazia (1 - Cheia, 0 - Não cheia)
	int Ret;

	if (Tamanho(P) == MAX_PILHA){
		Ret = 1;
	}
	else{
		Ret = 0;
	}	

	return Ret;
}

void Empilha(Pilha *P, int Codigo, string Nome, float Preco){	

	if (Pilha_Cheia(P) == 0){ //Há espaço na pilha
		P->Topo++;
		P->Lista[P->Topo].Codigo = Codigo;
		P->Lista[P->Topo].Nome = Nome;
		P->Lista[P->Topo].Preco = Preco;
	}
	else{
		cout << "Não há mais espaço na pilha de alunos!!" << endl;
	}
} 

Item * Desempilha(Pilha *P){		

	Item *Ret = NULL;
	//P->Lista[P->Topo]

	if (Pilha_Vazia(P) == 0){ //Há alunos na Turma			
		//Ret = T->Lista + T->Topo; //Ponteiro para o registro retirado
		Ret = &(P->Lista[P->Topo]);

		P->Topo--;	//Atualiza o topo				
	}
	else{

		cout << "Pilha vazia!!" << endl;
	}
	
	return Ret;
} 

void Imprime_Pilha(Pilha *P){
	int Cont;	
    

	cout<<"CÓDIGO\t"<<"\tNOME\t\t"<<"\tPREÇO\t\n";	

	for (Cont=P->Topo; Cont>=0; Cont--){
		cout<<"\t"<<P->Lista[Cont].Codigo<<"\t";
		cout<<"\t"<<P->Lista[Cont].Nome<<"\t\t";
		cout<<"\t"<<P->Lista[Cont].Preco<<"\n";
	}	
}

Pilha P;
Item *I;
int main(){	
	setlocale(LC_ALL,"Portuguese");
	
	Ini_Pilha(&P);
	
	Empilha(&P, 1, "1", 1); //Push
	Empilha(&P, 5, "5", 5);
	Empilha(&P, 9, "9", 9);
	Empilha(&P, 3, "3", 3);  	
	Imprime_Pilha(&P);
	
	Empilha(&P, 2, "2", 2);
	Imprime_Pilha(&P);
		
	I = Desempilha(&P);
	cout << "Valor do Topo: " << I->Codigo << endl;
		
	Imprime_Pilha(&P);
	
	Desempilha(&P); // Pop
	Desempilha(&P);
	Empilha(&P, 7, "7", 7);	
	Desempilha(&P);
	Desempilha(&P);
	Imprime_Pilha(&P);
	
	
	return 0;
}