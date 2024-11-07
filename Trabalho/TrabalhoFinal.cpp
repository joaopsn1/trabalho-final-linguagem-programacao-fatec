#include <iostream>
#include <string>
#include <list>
#include "Biblioteca.cpp"



using namespace std;

int opcao;
int opcao_livro;

// Menu principal
int menu() {
   system("cls");//limpa o cmd toda vez que volta para esse menu
   cout <<"\n[ 1 ] Cadastros de livros \n";
   cout <<"[ 2 ] Cadastro de usuarios \n";
   cout <<"[ 3 ] Emprestimo e devolucao \n";
   cout <<"[ 4 ] Busca e filtragem \n";
   cout <<"[ 5 ] Relatorio \n";
   cout <<"[ 6 ] Fim do App \n";
   cout << "\nOpcao: ";
   cin >> opcao;
   return opcao; 
}

// Menu de cadastro de livros
int menu_cadastro_livro() {
   cout << "\n.:: MENU DA BIBLIOTECA ::.\n";
   cout <<"[ 1 ] Adicionar Livro \n";
   cout <<"[ 2 ] Exibir Livros \n";
   cout <<"[ 3 ] Voltar ao menu principal \n";
   cout << "\nOpcao: ";
   cin >> opcao_livro;
   return opcao_livro;
}

int main() {
    cout << ".:: SISTEMA BIBLIOTECA ::.";

    while (true) {
        opcao = menu();

        switch (opcao) {
            case 1: // Menu de cadastro de livros
                while (true) {
                    opcao_livro = menu_cadastro_livro();

                    if (opcao_livro == 1) {
                        cadastrarLivro(); // Adiciona livro à lista
                    } else if(opcao_livro == 2){
                        exibirLivrosCadastrados();//exibir os livros no meu 
                    } else if (opcao_livro == 3) {
                        break; // Volta ao menu principal
                    } else {
                        cout << "Opcao invalida!" << endl;
                    }
                }
                break;

            case 6: // Finalizar o aplicativo
                cout << "Encerrando o aplicativo..." << endl;
                return 0;
            default:
                cout << "Opção inválida no menu principal." << endl;
                break;
        }
    }

    return 0;
}