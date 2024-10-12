#include <iostream>
#define max 5
using namespace std;

struct Books{
    int codigo;
    string titulo, autor;
    double preco;
};

struct Lista{
    struct Books b[max];
    int tam;
};

void criarLista(Lista *L){
    L->tam=0;
}

bool listaCheia(Lista *L){
    return L->tam == max;
}

bool listaVazia(Lista *L){
    return L->tam == 0;
}

int tamanhodaLista(Lista *L){
    return L->tam;
}

int posicao(Lista *L,int cod){
    int cont=0;
    while(cont<L->tam){
        if(L->b->codigo == cod){
            return cont;
        }else{
            cont++;
        }
    }
    return -1;
}

void inserir(Lista *L,int cod,string title,string autor,double prc){
    int pos;
    if(!listaCheia(L)){
        pos = posicao(L,cod);
        if(pos<0){
            L->b[L->tam].codigo = cod;
            L->b[L->tam].titulo = title;
            L->b[L->tam].autor = autor;
            L->b[L->tam].preco = prc;
            
            L->tam++;
        }else{
            cout<<"O código " << cod << " já existe!";
        }
    }else{
        cout<<"A lista está cheia!";
    }
}

void remover(Lista *L,int cod){
    int pos = posicao(L,cod);
    if(!listaVazia(L)){
        if(pos>=0){
            while(pos < L->tam-1){
                L->b[pos] = L->b[pos+1];
                pos++;
            }
            L->tam--;
            cout<<"O código "<<cod<<" foi excluído!";
        }else{
            cout<<"O código "<<cod<<" não existe!";
        }
    }else{
        cout<<"A lista está vazia!";
    }
}

void imprimirLista(Lista *L){
    int cont=0;
    while(cont < L->tam){
        cout << endl << L->b[cont].codigo << endl ;
        cout << L->b[cont].titulo << endl ;
        cout << L->b[cont].autor << endl ;
        cout << L->b[cont].preco << endl ;
        
        cont++;
    }
}

void menu(Lista *L){
    int opcao, codigo;
    string titulo, autor;
    double preco;
    
    do{
        cout << "\n______Menu______\n";
        cout << "1 - Inserir.\n";
        cout << "2 - Remover.\n";
        cout << "3 - Imprimir.\n";
        cout << "0 - Sair.\n";
        cin >> opcao;
        
        switch(opcao){
            
            case 1:
                cout << "\nDigite o código do livro.\n";
                cin >> codigo;
                cout << "Digite o título do livro.\n";
                cin >> titulo;
                cout << "Digite o autor do livro.\n";
                cin >> autor;
                cout << "Digite o preço do livro.\n";
                cin >> preco;
                inserir(L,codigo,titulo,autor,preco);
                break;
            
            case 2:
                cout << "\nDigite o código do livro que quer excluir.\n";
                cin >> codigo;
                remover(L,codigo);
                break;
            
            case 3:
                cout << "_______________Imprimindo Lista_______________";
                imprimirLista(L);
                break;
        }
    }while(opcao!=0);
}

Lista L;
int main()
{
    setlocale(LC_ALL,"Portuguese");
    criarLista(&L);
    menu(&L);

    return 0;
}
