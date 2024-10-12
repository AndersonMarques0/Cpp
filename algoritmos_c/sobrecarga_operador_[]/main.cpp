#include <iostream>
#include <iomanip>
using namespace std;

class Matriz
{
    private:
        static const int MAX=50;
        float n[MAX];
    public:
        Matriz();
        float& operator[](int indice);
        float media(int i);
};

Matriz::Matriz()
{
    for(int i=0;i<MAX;i++) n[i] = 0.0;
}

float& Matriz::operator[](int indice)
{
    static float lixo=-1;
    if( indice >= 0 && indice < MAX)
        return n[indice];
    else
        return lixo;
}

float Matriz::media(int i)
{
    float m=0.0;
    for(int j=0; j<i; j++)
        m += n[j];
        
    return m/static_cast<float>(i);
}

int main()
{
    Matriz notas;
    cout << setprecision(2);
    int i=0;
    
    do
    {
        cout << "Digite a nota do aluno " << (i+1) << ": ";
        cin>> notas[i];
    }while(notas[i++] >= 0);
    
    cout << endl << "Média das notas: " << notas.media(i-1) << endl;

    return 0;
}