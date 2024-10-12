#include <iostream>
#include <cstdlib>

using namespace std;

struct entrada{
    char txt;
    entrada *prox;
};

struct operador{
    char op;
    operador *prox;
};

struct numero{
    float num;
    numero *prox;
};

struct fila{
  entrada *inicio;
  entrada *fim;
};

struct pilhaOperador{
    operador *topo;
};

struct pilhaNumero{
    numero *topo;
};

void iniciaFila(fila *F){
    F->inicio = NULL;
    F->inicio = NULL;
}

void iniciaOperador(pilhaOperador *P){
    P->topo = NULL;
}

void iniciaNumero(pilhaNumero *P){
    P->topo = NULL;
}

bool filaVazia(fila *F){
    return F->inicio == NULL;
}

bool operadorVazio(pilhaOperador *P){
    return P->topo == NULL;
}

bool numeroVazio(pilhaNumero *P){
    return P->topo == NULL;
}

entrada *No_entrada(char txt){
    entrada *novo = new entrada;
    if(novo!=NULL){
        novo->txt = txt;
        novo->prox = NULL;
    }
    return novo;
}

operador *No_operador(char txt){
    operador *novo = new operador;
    if(novo!=NULL){
        novo->op = txt;
        novo->prox = NULL;
    }
    return novo;
}

numero *No_numero(float n){
    numero *novo = new numero;
    if(novo!=NULL){
        novo->num = n;
        novo->prox = NULL;
    }
    return novo;
}

void enqueue(fila *F,char txt){
    entrada *novo = No_entrada(txt);
    if(novo!=NULL){
        if(filaVazia(F)){
           F->inicio = novo;
        }else{
            F->fim->prox = novo;
        }
        F->fim = novo;
    }
}

entrada *dequeue(fila *F){
    entrada *ret;
    if(filaVazia(F)){
        ret = NULL;
    }else{
        ret = F->inicio;
        F->inicio =  F->inicio->prox;
        if(filaVazia(F)){
            F->inicio = F->fim->prox;
        }
    }
    return ret;
}

void pushOperador(pilhaOperador *P,char txt){
    operador *novo = No_operador(txt);
    if(novo!=NULL){
        novo->prox = P->topo;
        P->topo = novo;
    }
}

void pushNumero(pilhaNumero *P,float num){
    numero *novo = No_numero(num);
    if(novo!=NULL){
        novo->prox = P->topo;
        P->topo = novo;
    }
}

operador *popOperador(pilhaOperador *P){
    operador *ret;
    if(!operadorVazio(P)){
        ret = P->topo;
        P->topo = P->topo->prox;
    }
    return ret;
}

numero *popNumero(pilhaNumero *P){
    numero *ret;
    if(!numeroVazio(P)){
        ret = P->topo;
        P->topo = P->topo->prox;
    }
    return ret;
}

float somar(float n1,float n2){
    return n1 + n2;
}

float subtrair(float n1,float n2){
    return n1 - n2;
}

float multiplicacao(float n1,float n2){
    return n1 * n2;
}

float divisao(float n1,float n2){
    return n1 / n2;
}

void processarEntrada(fila *F,string entrada){
    
    for(int cont=0; cont<entrada.size();cont++){
        if(entrada[cont] != ' '){
            enqueue(F,entrada[cont]);
        }
    }
}


void gravarOperador(pilhaOperador *P,char item){
    
    if(item == '+'){
        pushOperador(P,'+');
    }else{
        if(item == '-'){
            pushOperador(P,'-');
        }
        
        if(item == '*'){
            pushOperador(P,'*');
        }
        
        if(item == '/'){
            pushOperador(P,'/');
        }
    }
}

float calcular(fila* F, pilhaOperador* OP, pilhaNumero* P) {
    float resultado = 0.0;

    while (!filaVazia(F)) {
        entrada* cont = dequeue(F);

        if (isdigit(cont->txt)) {
            float num = atof(&cont->txt);
            pushNumero(P, num);
        }else{
            if (cont->txt == '+' || cont->txt == '-' || cont->txt == '*' || cont->txt == '/') {
                while (!operadorVazio(OP) && (OP->topo->op == '*' || OP->topo->op == '/')) {
                    char op = popOperador(OP)->op;
                    float n2 = popNumero(P)->num;
                    float n1 = popNumero(P)->num;
    
                    if (op == '*') {
                        pushNumero(P, n1 * n2);
                    }
                    else if (op == '/') {
                        if (n2 != 0) {
                            pushNumero(P, n1 / n2);
                        }
                        else {
                            pushNumero(P, 0.0);  // Tratamento de erro, se necessário
                        }
                    }
                }

            pushOperador(OP, cont->txt);
            }
        }
    }

    while (!operadorVazio(OP)) {
        char op = popOperador(OP)->op;
        float n2 = popNumero(P)->num;
        float n1 = popNumero(P)->num;

        if (op == '+') {
            pushNumero(P, n1 + n2);
        }
        else if (op == '-') {
            pushNumero(P, n1 - n2);
        }
        else if (op == '*') {
            pushNumero(P, n1 * n2);
        }
        else if (op == '/') {
            if (n2 != 0) {
                pushNumero(P, n1 / n2);
            }
            else {
                pushNumero(P, 0.0);  // Tratamento de erro, se necessário
            }
        }
    }

    if (!numeroVazio(P)) {
        resultado = P->topo->num;
    }

    return resultado;
}

int main(){
    fila F;
    pilhaOperador OP;
    pilhaNumero P;

    iniciaFila(&F);
    iniciaOperador(&OP);
    iniciaNumero(&P);

    string expressao;
    cout << "Digite a expressao: ";
    getline(cin, expressao);

    processarEntrada(&F, expressao);
    float resultado = calcular(&F, &OP, &P);

    cout << "Resultado: " << resultado << endl;

    return 0;
}
