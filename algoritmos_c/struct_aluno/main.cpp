#include <iostream>

using namespace std;

int main()
{
    struct aluno{
        int matricula;
        string nome;
        double p1, p2;
        
    double media(double p1, double p2){
        return (p1+p2)/2;
    }
        
    }alunos[6];
    
    for(int i=0;i<6;i++)
    {
        cout<<"Digite o nome do(a) aluno(a): ";
        cin>>alunos[i].nome;
        cout<<"Digite o Nº de matrícula do(a) aluno(a): ";
        cin>>alunos[i].matricula;
        cout<<"Digite a primeira nota do(a) aluno(a): ";
        cin>>alunos[i].p1;
        cout<<"Digite a segunda nota do(a) aluno(a): ";
        cin>>alunos[i].p2;
        alunos[i].media(alunos[i].p1,alunos[i].p2); 
    
        if(alunos[i].media(alunos[i].p1,alunos[i].p2)>=6)
        {
            cout<<"O(A) aluno(a) "<<alunos[i].nome<<" foi aprovado(a).\n";
            cout<<"A sua média é "<<alunos[i].media(alunos[i].p1,alunos[i].p2)<<endl; 
        }
    }
    
    

    return 0;
}
