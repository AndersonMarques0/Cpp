#include <iostream>
#include <stdlib.h>

using namespace std;

struct Time{
	int Codigo;
	string Nome;
	int Ano_f; 
	Time *Prox;
};

struct Liga{ //Header/Cabe�alho
	Time *Topo;
	int Total;
};

void Ini_Lista(Liga *L){
	L->Topo = NULL;
	L->Total = 0;
}

int Lista_Vazia(Liga *L){
	
	return (L->Topo == NULL);		
}

Time *Criar_Time(int Codigo, string Nome, int Ano_f){
	Time *Item;

	Item = new Time;
	if (Item != NULL){
		Item->Codigo = Codigo;
		Item->Nome = Nome;
		Item->Ano_f = Ano_f;
		Item->Prox = NULL;
	}
	
	return Item;
}

int Empilhar(Liga *L, int Codigo, string Nome, int Ano_f){
	int Ret=1; //C�digo de Erro	
	Time* Item;
	
	Item = Criar_Time(Codigo, Nome, Ano_f);
	if (Item == NULL)
		Ret = -1; //N�o conseguiu aloicar espa�o na mem�ria
	else{ 			
		Item->Prox = L->Topo;
		L->Topo = Item;
				
		L->Total++;
	}
		
	return Ret;
}

Time* Desempilhar(Liga *L){
	Time* Ret;
	
	if (Lista_Vazia(L)){
		Ret = NULL; //Lista vazia
	}
	else{		
		Ret = L->Topo;		
		L->Topo = L->Topo->Prox;
		L->Total--;
	}
	
	return Ret;
}

void Imprime_Lista(Liga *L){
	Time* Item;
	int Cont=0;
	
	for(Item=L->Topo;Item!=NULL;Item = Item->Prox){
		cout << endl << "Time[" <<Cont<<"]";
		cout << endl << "Nome: " << Item->Codigo;
		cout << endl << "Nome: " << Item->Nome;
		cout << endl << "Ano funda��o: " << Item->Ano_f << endl;
		Cont++;
	}	
}

void Imprime_Lista_Rec(Time* Item){
		
	if (Item != NULL){
		cout << endl << "C�digo: " << Item->Codigo;
		cout << endl << "Nome: " << Item->Nome;
		cout << endl << "Ano funda��o: " << Item->Ano_f << endl;		
		
		Imprime_Lista_Rec(Item->Prox);
	}	
}

//-> Acesso ao campo da struct via ponteiro *().

void MostraMsgErro(int CodErro, string TipoOp){
	
	if (TipoOp == "INS"){
		switch(CodErro){
			case -1:
				cout << endl<< "ERRO INSER��O ["<<CodErro<<"]: Pilha cheia!!!" << endl;
				system("pause");
				break;											
		}
	}
	else{ //"REM"
		switch(CodErro){
			case -1:
				cout << endl<< "ERRO REMO��O ["<<CodErro<<"]: Pilha vazia!!!" << endl;
				system("pause");
				break;									
		}		
	}
}
/*
))())(
()(())
0 1 2...
char Sent[6];
Sent[0] =  ')';
Sent[1] =  ')';
Sent[2] =  '(';
Sent[3] =  ')';
Sent[4] =  ')';
Sent[5] =  '(';
*/
Liga T;
Time *Item;
int main(){	
	setlocale(LC_ALL,"Portuguese");
	
	//MostraMsgErro(Remover_Time(&T,50), "REM");
	Ini_Lista(&T);
	Empilhar(&T,50, "Palmeiras", 1914);
	Empilhar(&T,40, "Santos", 1909);
	Empilhar(&T,10, "Corinthians", 1910);
	Empilhar(&T,30, "S�o Paulo", 1930);
	Empilhar(&T,20, "Bragantino", 1970);		
	Imprime_Lista_Rec(T.Topo);
    system("pause");
	Desempilhar(&T); 
	Imprime_Lista_Rec(T.Topo);
	system("pause");
	Item = Desempilhar(&T);
	cout << endl << "Valor do c�digo desempilhado �: " << Item->Codigo;
	Imprime_Lista_Rec(T.Topo);
		
	return 0;
}  