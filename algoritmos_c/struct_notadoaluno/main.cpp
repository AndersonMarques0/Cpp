#include <iostream>

using namespace std;

struct Alunos
{
    int numeroDeMatricula;
    string nome;
    float prova1, prova2, media;
}aluno[2];

// função que imprime todos os alunos cadastrados ou somente os alunos aprovados

void decisaoImpressao(string decisao)
{
    if(decisao=="sim")
    {
        for(int i=0;i<2;i++)
        {
            cout<<endl;
            cout<<aluno[i].nome<<endl;
            cout<<aluno[i].numeroDeMatricula<<endl;
            cout<<aluno[i].media<<"\n\n";
        }
    }else
    {
        for(int i=0;i<2;i++)
        {
            if(aluno[i].media>=7)
            {
                cout<<endl;
                cout<<aluno[i].nome<<endl;
                cout<<aluno[i].numeroDeMatricula<<endl;
                cout<<aluno[i].media<<"\n\n";
            }
            
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    string decisao;
    
    // carregando dados no struct
    
    for(int i=0;i<2;i++)
    {
        cout<<"Digite o nome do aluno(a): ";
        cin>>aluno[i].nome;
        cout<<"Digite o número de matrícula: ";
        cin>>aluno[i].numeroDeMatricula;
        cout<<"Digite a nota da prova 1: ";
        cin>>aluno[i].prova1;
        cout<<"Digite a nota da prova 2: ";
        cin>>aluno[i].prova2;
        
        aluno[i].media = (aluno[i].prova1 + aluno[i].prova2)/2;
    }
    
    cout<<"Deseja imprimir todos os alunos ou apenas os aprovados?\n";
    cout<<"Digite \"sim\" para mostrar todos os alunos ou digite \"nao\" para imprimir os alunos aprovados.\n";
    cin>>decisao;
    
    // imprimindo os alunos cadastrados
    
    decisaoImpressao(decisao);

    return 0;
}