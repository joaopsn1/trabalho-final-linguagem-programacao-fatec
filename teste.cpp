#include <iostream>
using namespace std;
#define PRECO 1.99//definiu uma variavel
int main()
{

// definiu variaveis
char qualidade = 'A';
int pera = 3;
float peso = 2.5;


cout << "Existem " << pera << " peras de qualidade " << qualidade <<" pesando " << peso << " quilos." << endl;
cout << "O preco por quilo eh R$" << PRECO
<< ", o total eh R$" << peso * PRECO << endl; //printou e chamou as variaveis 


//<<endl -> encerra o programa
}