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

No* insereOrdenado(Arvore* Arv, int ValorNum, string ValorTexto, No* atual){
    No* item;
    
    if(Arv->Raiz == NULL){
        item = CriaNo(ValorNum, ValorTexto);
        Arv->Raiz = item;
        Arv->TotalElem++;
    }else{
        if(atual != NULL){ // procura na árvore até chegar no folha
            if(atual->ValorNum == ValorNum){
                item = NULL;
            }else{
                item = atual;
                if(ValorNum > atual->ValorNum){
                    atual->Dir = insereOrdenado(Arv, ValorNum, ValorTexto, atual->Dir);
                }else{
                    atual->Esq = insereOrdenado(Arv, ValorNum, ValorTexto, atual->Esq);
                }
                
            }
        }else{
            item = CriaNo(ValorNum, ValorTexto);
            Arv->TotalElem++;
        }
    }
    return item;
}

No *achaMaior(No* atual){
    No* item;
    
    if(atual->Dir == NULL){
        item = atual;
    }else{
        item = achaMaior(atual->Dir);
    }
    return item;
}

No* removeOrdenado(Arvore *Arv, int ValorNum, No* atual){
    No *item, *ant;
    
    if(atual!=NULL){
        
        if(atual->ValorNum == ValorNum){
            
            if(atual->Dir == NULL && atual->Esq == NULL){
                item = NULL;
            }else{
                
                if(atual->Esq == NULL){
                    item = atual->Dir;
                }else{
                    
                    if(atual->Dir == NULL){
                        item = atual->Esq;
                    }else{
                        item = atual;
                        ant = achaMaior(atual->Esq);
                        
                        atual->ValorNum = ant->ValorNum;
                        atual->ValorTexto = ant->ValorTexto;
                        
                        atual->Esq = removeOrdenado(Arv, ant->ValorNum, atual->Esq); 
                    }
                }
            }
            Arv->TotalElem--;
        }else{
            item = atual;
            if(ValorNum > atual->ValorNum){
                atual->Dir = removeOrdenado(Arv, ValorNum, atual->Dir);
            }else{
                atual->Esq = removeOrdenado(Arv, ValorNum, atual->Esq);
            }
        }
        
    }else{
        item = NULL;
    }
    
    return item;
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
