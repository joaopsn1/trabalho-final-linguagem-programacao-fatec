#include <iostream>
#include <string>
using namespace std;

int opcao;
int opcao_livro;

struct Node {
    string nome;
    Node* proximo;
};

// Função para adicionar um nome na lista
void adicionar_nome(Node** head, string novo_nome) {
    Node* newnode = new Node();
    newnode->nome = novo_nome;
    newnode->proximo = *head;
    *head = newnode; // Atualiza o head para o novo nó
}

// Função para exibir todos os nomes na lista
void todos_os_nomes(Node* node) {
    if (node == nullptr) {
        cout << "A lista está vazia." << endl;
        return;
    }

    cout << "\nLista de nomes: " << endl;
    while (node != nullptr) {
        cout << "- " << node->nome << endl;
        node = node->proximo;
    }
}

// Menu principal
int menu() {
   cout <<"\n[ 1 ] Cadastros de livros \n";
   cout <<"[ 2 ] Cadastro de usuarios \n";
   cout <<"[ 3 ] Emprestimo e devolucao \n";
   cout <<"[ 4 ] Busca e filtragem \n";
   cout <<"[ 5 ] Relatorio \n";
   cout <<"[ 6 ] Exibir todos os livros \n";
   cout <<"[ 7 ] Fim do App \n";
   cout << "\nOpcao: ";
   cin >> opcao;
   return opcao; 
}

// Menu de cadastro de livros
int menu_cadastro_livro() {
   cout << "\n.:: MENU DA BIBLIOTECA ::.\n";
   cout <<"[ 1 ] Adicionar Livro \n";
   cout <<"[ 2 ] Voltar ao menu principal \n";
   cout << "\nOpcao: ";
   cin >> opcao_livro;
   return opcao_livro;
}

// Função para adicionar livro à lista
void adicionar_livro(Node** head) {
    string nome_livro;
    cout << "\n.:: ADICIONAR LIVRO NA BIBLIOTECA ::.\n";
    cout << "Nome: ";
    cin.ignore();
    getline(cin, nome_livro);
    adicionar_nome(head, nome_livro); // Adiciona o livro à lista
    cout << "Livro adicionado com sucesso!" << endl;
}

int main() {
    Node* listaLivros = nullptr; // Inicializa a lista como vazia

    while (true) {
        opcao = menu();

        switch (opcao) {
            case 1: // Menu de cadastro de livros
                while (true) {
                    opcao_livro = menu_cadastro_livro();

                    if (opcao_livro == 1) {
                        adicionar_livro(&listaLivros); // Adiciona livro à lista
                    } else if (opcao_livro == 2) {
                        break; // Volta ao menu principal
                    } else {
                        cout << "Opção inválida!" << endl;
                    }
                }
                break;
            
            case 6: // Exibir todos os livros
                todos_os_nomes(listaLivros); // Exibe a lista de livros
                break;

            case 7: // Finalizar o aplicativo
                cout << "Encerrando o aplicativo..." << endl;
                return 0;

            default:
                cout << "Opção inválida no menu principal." << endl;
                break;
        }
    }

    return 0;
}
