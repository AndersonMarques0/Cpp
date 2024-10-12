#include <iostream>

using namespace std;

int main()
{
    // definindo o registro que representará cada elemento da lista
    struct LISTA{
        int num;
        LISTA* prox;
    };
    
    // a lista está vazia, logo, o ponteiro inicio tem o valor NULL
    // o ponteiro inicio conterá o endereço do primeiro elemento da lista
    
    LISTA* inicio = NULL;
    
    // o ponteiro fim conterá o endereço do último elemento da LISTA
    
    LISTA* fim = NULL;
    
    // o ponteiro aux é um ponteiro auxiliar
    
    LISTA* aux;
    
    // o ponteiro anterior é um ponteiro auxiliar
    
    LISTA* anterior;
    
    // apresentando o menu de opções
    
    int op, numero, achou;
    
    do{
        cout<<"\nMenu de Opções\n";
        cout<<"\n1 - Inserir no inicio da lista";
        cout<<"\n2 - Inserir no fim da lista";
        cout<<"\n3 - Consultar toda a lista";
        cout<<"\n4 - Remover da lista";
        cout<<"\n5 - Esvaziar a lista";
        cout<<"\n6 - Sair";
        cout<<"\nDigite sua opção: ";
        cin>>op;
        if(op<1 || op>6){
            cout<<"Opção inválida!!";
        }
        
        if(op==1){
            cout<<"\nDigite o número a ser inserido no inicio da lista: ";
            LISTA* novo = new LISTA();
            cin>>novo->num;
            if(inicio==NULL)
            {
                // a lista estava vazia e o elemento inserido será o primeiro e o último elemento
                
                inicio = novo;
                fim = novo;
                fim->prox = NULL;
            }else
            {
                // a lista já contém elementos e o novo elemento será inserido no inicio da lista
                
                novo->prox = inicio;
                inicio = novo;
            }
            cout<<"Numero inserido no inicio da lista.";
        }
        
        if(op==2)
        {
            cout<<"\nDigite o numero a ser inserido no fim da lista: ";
            LISTA* novo = new LISTA();
            cin>>novo->num;
            if(inicio==NULL)
            {
                // a lista está vazia e o elemento inserido será o primeiro e o último
                
                inicio = novo;
                fim = novo;
                fim->prox == NULL;
            }else
            {
                // a lista já contém elementos e o novo elemento será inserido no fim da lista
                
                fim->prox = novo;
                fim = novo;
                fim->prox = NULL;
            }
            cout<<"Numero inserido no fim da lista!!";
        }
        
        if(op==3)
        {
            if(inicio==NULL)
            {
                // a lista está vázia
                
                cout<<"\nA lista esta vazia!!";
            }else
            {
                // a lista contém elementos e estes serão mostrados no inicio ao fim
                
                cout<<"\nConsultando toda a lista\n";
                aux = inicio;
                while(aux != NULL)
                {
                    cout<<aux->num<<" ";
                    aux = aux->prox;
                }
            }
        }
        
        if(op==4)
        {
            if(inicio==NULL)
            {
                // a lista está vazia
                
                cout<<"\nLista vazia!!";
            }else
            {
                // a lista contém elementos e o elemento a ser removido deve ser digitado
                
                cout<<"\nDigite o elemento a ser removido: ";
                cin>>numero;
                
                // todas as ocorrências da lista, iguais ao número digitado, serão removidas
                
                aux = inicio;
                anterior = NULL;
                achou = 0;
                while(aux != NULL)
                {
                    if(aux->num==numero)
                    {
                        // o numero digitado foi encontrado na lista e será removido
                        
                        achou = achou + 1;
                        if(aux==inicio)
                        {
                            // o numero a ser removido é o primeiro da lista
                            
                            inicio = aux->prox;
                            delete(aux);
                            aux = inicio;
                        }else if(aux==fim)
                        {
                            // o numero a ser removido é o último da lista
                            
                            anterior->prox = NULL;
                            fim = anterior;
                            delete(aux);
                            aux = NULL;
                        }else
                        {
                            // o numero a ser removido está no meio da lista
                            
                            anterior->prox = aux->prox;
                            delete(aux);
                            aux = anterior->prox;
                        }
                    }else
                    {
                        anterior = aux;
                        aux = aux->prox;
                    }
                }
                if(achou==0)
                {
                    cout<<"Numero nao encontrado";
                }else if(achou==1)
                {
                    cout<<"Numero removido 1 vez";
                }else
                {
                    cout<<"Numero removido"<<achou<<" vezes.";
                }
            }
        }
        
        if(op==5)
        {
            if(inicio==NULL)
            {
                // a lista está vazia
                
                cout<<"\nLista vazia!!";
            }else
            {
                // a lista será esvaziada
                
                aux = inicio;
                while(aux != NULL)
                {
                    inicio = inicio->prox;
                    delete(aux);
                    aux=inicio;
                }
                cout<<"Lista esvaziada.";
            }
        }
        
    }while(op!=6);

    return 0;
}