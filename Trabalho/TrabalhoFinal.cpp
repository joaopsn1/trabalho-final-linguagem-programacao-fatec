#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "Biblioteca.cpp"
#include "menu.cpp"

using namespace std;

int main() {
    int opcao, opcaoLivro, opcaoUsuario, opcaoBusca, opcaoEmprestimoDevolucao;
    std::string autorProcurado;

    while (true) { // loop infinito para ficar executando
        opcao = menu();

        switch (opcao) {
            case 1: // Menu de cadastro de livros
                while (true) {
                    opcaoLivro = menuCadastroLivro();

                    if (opcaoLivro == 1) {
                        cadastrarLivro(); // Adiciona livro à lista
                    } else if(opcaoLivro == 2){
                        exibirLivrosCadastrados(); // exibir os livros no meu 
                    } else if (opcaoLivro == 3) {
                        removerLivrosPorISBN(); // remover livros pelo código   
                    } else if (opcaoLivro == 4) {
                        editarQuantidade(); // editar quantidade de livros  
                    } else if (opcaoLivro == 5) {
                        break; // Volta ao menu principal
                    } else {
                        cout << "Opcao invalida!" << endl;
                    }
                }
                
                break;
            case 2:
                while (true) {
                    opcaoUsuario = menuCadastroUsuario();

                    if(opcaoUsuario == 1) {
                        cadastrarUsuario(); // adicionar usuario
                    } else if (opcaoUsuario == 2) {
                        break; // Volta ao menu principal
                    } else {
                        cout << "Opcao invalida!" << endl;
                    }
                }
                break;
            case 3:
                while (true) {
                    opcaoEmprestimoDevolucao = menuEmprestimoDevolucao();

                    if(opcaoEmprestimoDevolucao == 1) {
                        emprestimoDeLivros(); // emprestar livros
                    } else if (opcaoEmprestimoDevolucao == 2) {
                        devolucaoDeLivros(); // devolver livros
                    } else if (opcaoEmprestimoDevolucao == 3) {
                        break; // volta ao menu principal
                    } else {
                        cout << "Opcao invalida!" << endl;
                    }
                }
                break;
            case 4:
                while (true) {
                    opcaoBusca = menuFiltragem();

                    if (opcaoBusca == 1) {
                        pesquisarLivrosPorAutor(); // Pesquisa de livros por autor
                    } else if (opcaoBusca == 2) {
                        pesquisarLivrosPorTitulo(); // Pesquisa de livros por titulo
                    } else if (opcaoBusca == 3) {
                        pesquisarLivrosPorGenero(); // Pesquisa de livros por genero
                    } else if (opcaoBusca == 4) {
                        break; // volta ao menu principal
                    } else {
                        cout << "Opcao invalida!" <<endl ;
                    }
                }
                break;

            case 5:
                cout << "Relatorio";
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