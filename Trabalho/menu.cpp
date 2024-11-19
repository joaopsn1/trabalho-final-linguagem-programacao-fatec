#include <iostream>
#include <string>

int opcao;
int opcaoLivro;
int opcaoUsuario;
int opcaoRelatorio;
int opcaoRelatorioBiblioteca;

using namespace std;

int menu() {
   system("cls");//limpa o cmd toda vez que volta para esse menu
   cout << ".:: SISTEMA BIBLIOTECA ::.\n";
   cout << "[ 1 ] Cadastro de livros \n";
   cout << "[ 2 ] Cadastro de usuarios \n";
   cout << "[ 3 ] Emprestimo e devolucao \n";
   cout << "[ 4 ] Busca e filtragem \n";
   cout << "[ 5 ] Relatorio \n";
   cout << "[ 6 ] Fim do App \n";
   cout << "\nOpcao: ";
   cin >> opcao;
   return opcao; 
}

int menuFiltragem() {
   system("cls"); //limpa o cmd toda vez que volta para esse menu
   cout << ".:: BUSCA E FILTRAGEM ::.\n";
   cout << "[ 1 ] Busca por autor \n";
   cout << "[ 2 ] Busca por titulo \n";
   cout << "[ 3 ] Busca por genero \n";
   cout << "[ 4 ] Voltar ao menu principal \n";
   cout << "\nOpcao: ";
   cin >> opcao;
   return opcao; 
}

// Menu de cadastro de livros
int menuCadastroLivro() {
   cout << "\n.:: MENU DA BIBLIOTECA ::.\n";
   cout << "[ 1 ] Adicionar Livro \n";
   cout << "[ 2 ] Exibir Livros \n";
   cout << "[ 3 ] Remover Livro \n";
   cout << "[ 4 ] Editar Quantidade \n";
   cout << "[ 5 ] Voltar ao menu principal \n";
   cout << "\nOpcao: ";
   cin >> opcaoLivro;
   return opcaoLivro;
}

//menu de cadastro de usuario
int menuCadastroUsuario(){
   cout << "\n.:: MENU DA BIBLIOTECA ::.\n";
   cout << "[ 1 ] Adicionar Usuario \n";
   cout << "[ 2 ] Exibir Usuarios cadastrados \n";
   cout << "[ 3 ] Voltar ao menu principal \n";
   cout << "\nOpcao: ";
   cin >> opcaoUsuario;
   return opcaoUsuario;
}

//menu de cadastro de usuario
int menuEmprestimoDevolucao(){
   cout << "\n.:: EMPRESTIMO/DEVOLUCAO ::.\n";
   cout << "[ 1 ] Emprestimo \n";
   cout << "[ 2 ] Devolucao \n";
   cout << "[ 3 ] Exibir Emprestimos \n";
   cout << "[ 4 ] Voltar ao menu principal \n";
   cout << "\nOpcao: ";
   cin >> opcaoUsuario;
   return opcaoUsuario;
}

//menu de relatorio
int menuRelatorio(){
   cout << "\n.:: MENU DE RELATORIO ::.\n";
   cout << "[ 1 ] Relatorio de Livros \n";
   cout << "[ 2 ] Livro com mais Emprestimos \n";
   cout << "[ 3 ] Usuario com mais Emprestimos \n";
   cout << "[ 4 ] Voltar ao menu principal \n";
   cout << "\nOpcao: ";
   cin >> opcaoRelatorio;
   return opcaoRelatorio;
}

//menu de relatorio  biblioteca exibir usuario e livros
int menuRelatorioBiblioteca(){
   cout << "\n.:: MENU DE RELATORIO GERAL DA BIBLIOTECA ::.\n";
   cout << "[ 1 ] Exibir todos os Livros \n";
   cout << "[ 2 ] Exibir Usuario cadastrados \n";
   cout << "[ 3 ] Voltar ao menu principal \n";
   cout << "\nOpcao: ";
   cin >> opcaoRelatorioBiblioteca;
   return opcaoRelatorioBiblioteca;
}