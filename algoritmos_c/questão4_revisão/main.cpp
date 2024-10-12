#include <iostream>
#include <iomanip>

using namespace std;

int
main ()
{
  int num_carteira, num1, qtdd, carteira_lida = 0, maior_num_multa, contador = 0;
  double multa, soma, somatudo = 0, total, maior;

  do
    {
      num1 = 1;
      soma = 0;
      cout << "Digite o número da sua carteira de motorista: ";
      cin >> num_carteira;
      cout << "Digite a quantidade de multas que possui: ";
      cin >> qtdd;
      
      if (contador == 0)
	{
	  maior = qtdd;
	}else
	{
	    if (qtdd > maior)
	    {
    	  maior = qtdd;
    	  maior_num_multa = num_carteira;
    	  
	    }
	}
	
      while (num1 <= qtdd)
	{
	  cout << "Digite o valor da sua multa: ";
	  cin >> multa;
	  soma = soma + multa;
	  somatudo = somatudo + multa;

	  if (num1 == qtdd)
	    {
	      cout << "Carteira número: " << num_carteira << ".\n";
	      cout << "Valor da sua multa é " << soma << endl;
	    }

	  num1++;
	}
    
      contador++;
      carteira_lida++;
    }
  while (carteira_lida < 3);

  cout << "Valor total de todas as multas somadas é R$ " << somatudo << endl;
  cout << "A maior número de multas foi da carteira de motorista " <<
    maior_num_multa << " e a quantidade de multas foi " << maior;
  return 0;
}

