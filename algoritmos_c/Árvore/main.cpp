#include <iostream>

using namespace std;

struct No{
	int ValorNum;
	string ValorTexto;
	No* Esq;
	No* Dir;
};

//header ou cabeçalho ou cabeça

struct Arvore{
	No* Raiz;		
	int TotalElem;
};

void Ini_Arvore(Arvore* Arv){
	Arv->Raiz = NULL;
	Arv->TotalElem = 0;
}

No* CriaNo(int ValorNum, string ValorTexto){
	No* Ret;

	Ret = new No;
	Ret->ValorNum = ValorNum;
	Ret->ValorTexto = ValorTexto;	
	Ret->Esq = NULL;	
	Ret->Dir = NULL;	

	return Ret;
}

No* InsereNoArv(Arvore* Arv, int ValorNum, string ValorTexto, No* NoPai, string TipoLig){
	No *Item, *Aux;

	//Aloca espaço, grava os dados e retorna o ponteiro pro elemento	
	Item = CriaNo(ValorNum, ValorTexto);
	if (NoPai != NULL){// Se passou o pai, insere diretamente
		if (TipoLig == "E"){
			NoPai->Esq = Item;	
		}
		else{
			NoPai->Dir = Item;
		}				
	}
	else{	
		if (Arv->Raiz == NULL){//árvore Vazia
			Arv->Raiz = Item;			
		}	
		else{
			Item = NULL;
		}			
	}

	if (Item != NULL){
		Arv->TotalElem++;
	}
	
	return Item;
}

No* InsereNoArvOrd(Arvore* Arv, int ValorNum, string ValorTexto, No* NoAtual){
	No *Item, *Aux;
	
	if (Arv->Raiz == NULL){
		Item = CriaNo(ValorNum, ValorTexto);
		Arv->Raiz = Item; 
		Arv->TotalElem++;
	}
	else{
		if (NoAtual != NULL){ //Procura na �rvore at� chegar ao n� folha
			if (NoAtual->ValorNum == ValorNum){
				Item = NULL; //Erro: Item j� existe!!
			}
			else{
				Item = NoAtual;
				if (ValorNum > NoAtual->ValorNum){ //Maior - Lado direito
					NoAtual->Dir = InsereNoArvOrd(Arv, ValorNum, ValorTexto, NoAtual->Dir);			
				}
				else{ //Menor - Lado esquerdo
					NoAtual->Esq = InsereNoArvOrd(Arv, ValorNum, ValorTexto, NoAtual->Esq);
				}
			}			
		}
		else{ //Encontrou o n� folha correto
			Item = CriaNo(ValorNum, ValorTexto);
			Arv->TotalElem++;
		}									
	}
	
	return Item;
}

No* Acha_Maior(No* NoAtual){
	No *Item;
	
	if (NoAtual->Dir == NULL){
		Item = NoAtual;
	}
	else{
		Item = Acha_Maior(NoAtual->Dir);
	}
	
	return Item;
}


No* RemoveNoArvOrd(Arvore* Arv, int ValorNum, No* NoAtual){
	No *Item, *Ant;
	
	if (NoAtual != NULL){ //Procura na �rvore at� chegar ao n� folha
		if (NoAtual->ValorNum == ValorNum){ //Encontrou o item
			if (NoAtual->Esq == NULL && NoAtual->Dir == NULL){ //N�o tem filhos
				Item = NULL;
			}
			else{
				if (NoAtual->Esq == NULL){ //1 filho: Filho est� no n� direito
					Item = NoAtual->Dir;
				}
				else{
					if (NoAtual->Dir == NULL){ //1 filho: Filho est� no n� esquerdo
						Item = NoAtual->Esq;	
					}
					else{ //2 filhos: trocar pelo maior filho da sub-�rvore esquerda
						Item = NoAtual;
						Ant = Acha_Maior(NoAtual->Esq);	
						//Copia	os dados do maior antecessor na sub-�rvore esquerda para o n� atual
						NoAtual->ValorNum = Ant->ValorNum;
						NoAtual->ValorTexto = Ant->ValorTexto;
						//Remove n� antecessor atualizando a sub-�rvore esquerda
						NoAtual->Esq = RemoveNoArvOrd(Arv, Ant->ValorNum, NoAtual->Esq);
					}
				}
			}
			Arv->TotalElem--;		
		}
		else{
			Item = NoAtual;
			if (ValorNum > NoAtual->ValorNum){ //Maior - Lado direito
				NoAtual->Dir = RemoveNoArvOrd(Arv, ValorNum, NoAtual->Dir);			
			}
			else{ //Menor - Lado esquerdo
				NoAtual->Esq = RemoveNoArvOrd(Arv, ValorNum, NoAtual->Esq);
			}
		}			
	}
	else{ //N�o encontrou o item!!
		Item = NULL;		
	}									
	
	return Item;
}

void ImprimeArvore(No* NoArv, string Tipo, char TipoValor) {
	
	if (NoArv != NULL){		//pré-ordem
		if (Tipo == "PRE"){
			if (TipoValor == 'T'){
				cout << NoArv->ValorTexto << ", ";	
			}			
			else{
				cout << NoArv->ValorNum << ", ";	
			}
		}
				
		ImprimeArvore(NoArv->Esq, Tipo, TipoValor);						
		
		if (Tipo == "CEN"){
			if (TipoValor == 'T'){
				cout << NoArv->ValorTexto << ", ";	
			}			
			else{
				cout << NoArv->ValorNum << ", ";	
			}
		}
		
		ImprimeArvore(NoArv->Dir, Tipo, TipoValor);		

		if (Tipo == "POS"){
			if (TipoValor == 'T'){
				cout << NoArv->ValorTexto << ", ";	
			}			
			else{
				cout << NoArv->ValorNum << ", ";	
			}
		}

	}
}

Arvore Arv;
No *Item, *ItemD, *ItemE;
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	Ini_Arvore(&Arv);
	
	Item = InsereNoArv(&Arv, 0, "*", NULL, ""); //raiz 
	
	ItemE = InsereNoArv(&Arv, 0, "5", Item, "E"); //No esquerdo (folha)
	ItemD = InsereNoArv(&Arv, 0, "+", Item, "D"); //Nodireito
	
	Item = InsereNoArv(&Arv, 0, "*", ItemD, "E"); //No esquerdo
	InsereNoArv(&Arv, 0, "7", ItemD, "D"); //No direito (folha)
	
	ItemE = InsereNoArv(&Arv, 0, "+", Item, "E"); //No esquerdo	
	ItemD = InsereNoArv(&Arv, 0, "*", Item, "D"); //No direito
	
	InsereNoArv(&Arv, 0, "9", ItemE, "E"); //No esquerdo (folha)	
	InsereNoArv(&Arv, 0, "8", ItemE, "D"); //No direito	(folha)
	
	InsereNoArv(&Arv, 0, "4", ItemD, "E"); //No esquerdo (folha)	
	InsereNoArv(&Arv, 0, "6", ItemD, "D"); //No direito (folha)
	
	if (Arv.Raiz != NULL){
		//*, 5, +, *, +, 9, 8, *, 4, 6, 7
		//ImprimeArvore(Arv.Raiz, "PRE", 'T');		
		
		//5, *, 9, +, 8, *, 4, *, 6, +, 7
		//ImprimeArvore(Arv.Raiz, "CEN", 'T');		
		
		//5, 9, 8, +, 4, 6, *, *, 7, +, *
		ImprimeArvore(Arv.Raiz, "POS", 'T');	
	}
	
	return 0;
}
