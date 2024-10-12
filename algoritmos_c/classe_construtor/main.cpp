#include <iostream>

using namespace std;

class Data
{
    private: 
        int dia, mes, ano;
    public:
        Data();
        /*
        Data() : dia(1), mes(1), ano(1)
        {}
        */
        // Data(int d, int m, int a);
        int Bissexto()
        {
            return (ano%4==0 && ano%100 || ano%400==0);
        }
        
        void initData(int d, int m, int a);
        void printData();
        void printSigno();
        void printBissexto();
};

Data::Data() : dia(1), mes(1), ano(1)
{
    
}

/*
Data::Data(int d, int m, int a)
{
    initData(d,m,a);
}
*/

void Data::initData(int d, int m, int a)
{
    
    int dmes[] = { 0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30};
    ano = a > 0 ? a : 1; // valida ano
    dmes[2] = dmes[2] + Bissexto();
    mes = m >= 1 && m<=12 ? m : 1; // valida mes
    dia = d>= 1 && d<= dmes[mes] ? d : 1; // valida dia;
}

void Data::printData()
{
    char nome[13][10] =
    {"zero","Janeiro","Fevereiro","Março","Abril","Maio","Junho","Julho",
        "Agosto","Setembro","Outubro","Novembro","Dezembro"};
    
    cout << endl << dia << " de " << nome[mes] << " de " << ano << endl;
}

void Data::printSigno()
{
    char nsigno[14][13] = 
    {"zero","Capricórnio","Aquário","Peixes","Áries","Touro","Gêmeos",
     "Câncer","Leão","Virgem","Libra","Escorpião","Sagitário","Capricórnio"};
     
    int sig[] = {0,20,19,20,20,20,20,21,22,22,22,21,21};
    
    if( dia < sig[mes])
        cout << "Signos: " << nsigno[mes] << endl;
    else
        cout << "Signo: " << nsigno[mes+1] << endl;
}

void Data::printBissexto()
{
    if(Bissexto())
        cout << "Ano é bissexto." << endl;
    else
        cout << "Ano não é bissexto." << endl;
}

int main()
{
    Data x;
    
    x.printData();
    x.printSigno();
    x.printBissexto();
    

    return 0;
}