#include <iostream>
#include <string>
#include <list>
#include "Biblioteca.cpp"
#include "menu.cpp"

using namespace std;

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
            case 2:
                while (true){
                    opcao_usuario = menu_cadastro_usuario();

                    if(opcao_usuario == 1){
                        cadastrarUsuario();//adicionar usuario
                    }else if (opcao_usuario == 2) {
                        break; // Volta ao menu principal
                    }else {
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