#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string converteNumeroEmString(int numero)
{
    return to_string(numero);
}

int comprimentoString(string palavra)
{
    return palavra.length();
}

vector<char> vetorString(string valor)
{
   vector<char> vetor(valor.begin(),valor.end());
   return vetor;
}

vector<char> inverteVetor(vector<char> vetor)
{
    reverse(vetor.begin(),vetor.end());
    return vetor;
}

int main() {
    int numero, tamanhoNumeroCovertidoEmString;
    string numeroString, numeroConvertidoEmString;
    
    cout<<"Este programa mostra o inverso do número digitado.\n";
    cout<<"Digite um número: ";
    cin>>numero;
    numeroConvertidoEmString = converteNumeroEmString(numero);
    
    tamanhoNumeroCovertidoEmString = comprimentoString(numeroConvertidoEmString);
    
    vector<char> vetor = vetorString(numeroConvertidoEmString);
    
    vector<char> vetorInvertido = inverteVetor(vetor);
    
    cout<<"Numero invertido: ";
    for(char c : vetorInvertido)
    {
        cout<<c;
    }
    cout<<endl;
    return 0;
}