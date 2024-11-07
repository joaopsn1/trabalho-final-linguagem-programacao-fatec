#include <iostream>
using namespace std;
int opcao;
int opcao_livro;
string nome;
string autor;
int isbn;
string genero;
int quantidade;
//testando isso aqui

int menu(){
   cout <<"[ 1 ] Cadastros de livros \n";
	cout <<"[ 2 ] Cadastro de usuarios \n";
	cout <<"[ 3 ] Emprestimo e devolucao \n";
	cout <<"[ 4 ] Busca e filtragem \n";
   cout <<"[ 5 ] Relatorio \n";
   cout <<"[ 6 ] Fim do App \n";
	cout << "\nOpcao: ";
   cin >> opcao;
   return opcao; 
}
int menu_cadastro_livro(){
   cout << "\n.:: MENU DA BIBLIOTECA ::.\n";
   cout <<"[ 1 ] Adicionar Livro \n";
	cout <<"[ 2 ] Editar Livro \n";
	cout <<"[ 3 ] Remover Livro \n";
   cout <<"[ 4 ] Voltar ao menu principal \n";
	cout << "\nOpcao: ";
   cin >> opcao_livro;
   return opcao_livro;
}
void adicionar_livro(){
   cout << "\n.:: ADICIONAR LIVRO NA BIBLIOTECA ::.\n\n";
   cout << "Nome: ";
   cin >> nome;
   cout << "autor: ";
   cin >> autor;
   cout << "isbn: ";
   cin >> isbn;
   cout << "genero: ";
   cin >> genero;
   cout << "quantidade: ";
   cin >> quantidade;

}
int main(){
   while(true){
         opcao = menu();

         switch (opcao)
         {
         case 1:
            opcao_livro = menu_cadastro_livro();
            adicionar_livro();



            break;
         
         default:
            break;
         }
   }


   return 0;
}

