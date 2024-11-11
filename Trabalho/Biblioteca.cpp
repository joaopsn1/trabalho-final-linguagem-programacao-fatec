#include <iostream>
#include <string>
#include <list>
#include "Usuarios.cpp"
#include "Livro.cpp"
#include <algorithm>

using namespace std;

list<Usuarios> usuarios;
list<Livro> livros;

// Cadastrar Usuários na biblioteca
void cadastrarUsuario() {
    string nome, endereco, contato;

    cout << "\nNome: ";
    std::cin.ignore();
    std::getline(std::cin, nome);
    cout << "Endereco: ";
    std::cin.ignore();
    std::getline(std::cin, endereco);
    cout << "Contato: ";
    std::cin.ignore();
    std::getline(std::cin, contato);

    usuarios.emplace_back(nome, endereco, contato); // Adicionando novo objeto Usuarios a Lista
    cout << "Usuario cadastrado com sucesso!" << endl;
}

// Exibir lista de usuários cadastrados
void exibirUsuariosCadastrados() {
    if (usuarios.empty()) {
        cout << "Nenhum usuario cadastrado" << endl;
        return;
    }

    for (const auto &usuario : usuarios) {
        usuario.exibirInformacoes();
    }
}

void cadastrarLivro() {
    string titulo, autor, genero;
    int isbn, quantidade;

    cout << "Titulo: ";
    std::cin.ignore();
    std::getline(std::cin, titulo);
    cout << "Autor: ";
    std::getline(std::cin, autor);
    cout << "ISBN: ";
    cin >> isbn;
    cout << "Genero: ";
    std::cin.ignore();
    std::getline(std::cin, genero);
    cout << "Quantidade: ";
    cin >> quantidade;

    livros.emplace_back(titulo, autor, isbn, genero, quantidade); // Adicionando novo objeto Livros a Lista
    cout << "Livro cadastrado com sucesso!" << endl;
}

// Exibir lista de usuários cadastrados
void exibirLivrosCadastrados() {
    cout << "\n.:: LIVROS CADASTRADOS ::.\n";
    if (livros.empty()) {
        cout << "Nenhum livro cadastrado" << endl;
        return;
    }

    for (const auto &livro : livros) {
        livro.exibirInformacoes();
        cout << "------------------------\n";
    }
}

void removerLivrosPorISBN() {
    Livro livro;
    int isbnParaRemover;
    cout << "\nDigite o ISBN do livro para remove-lo: ";
    cin >> isbnParaRemover;

    int afterSize = livros.size();

    livros.remove_if([isbnParaRemover](const Livro &livro)
                     { return livro.getISBN() == isbnParaRemover; });

    if (livros.size() < afterSize) {
        cout << "Livro removido com sucesso!\n";
    } else {
        cout << "Livro nao cadastrado no sistema!\n";
    }
}

void editarQuantidade() {
    int quantidadeAdicionarRetirar, escolha, isbn;

    cout << "Digite o ISBN do livro para procura: ";
    cin >> isbn;
    
    for(Livro &livro : livros) {
        if (livro.getISBN() != isbn) {
            cout << "Livro nao encontrado!" << endl;
            return;
        }
    }

    cout << "Digite a quantidade para adicionar/retirar: ";
    cin >> quantidadeAdicionarRetirar;
    cout << "[1] Adicionar\n";
    cout << "[2] Retirar\n";
    cout << "Digite a opcao: ";
    cin >> escolha;

    for(Livro &livro : livros) {
        if (escolha == 1) {
            livro.getQuantidade() += quantidadeAdicionarRetirar;
        } else if (escolha == 2) {
            if (quantidadeAdicionarRetirar > livro.getQuantidade()) {
                cout << "Quantidade indisponivel para retirada\n";
                return;
            }
            livro.getQuantidade() -= quantidadeAdicionarRetirar;
        } else {
            cout << "Opcao Invalida!\n";
        }
    }
}

// Função para pesquisar livros por autor
void pesquisarLivrosPorAutor() {
    Livro livro;
    bool encontrado = false;
    std::string autorProcurado;

    std::cout << "Digite o nome do autor para buscar: ";
    std::cin.ignore(); // Limpa qualquer caractere restante do buffer
    std::getline(std::cin, autorProcurado);

    std::cout << "Pesquisando livros do autor: " << autorProcurado << std::endl;

    for (const auto &livro : livros) {
        if (livro.getAutor() == autorProcurado) {
            cout << "\n";
            livro.exibirInformacoes();
            encontrado = true;
            std::cout << "---------------------" << std::endl;
            std::cin.get();
        }
    }

    if (!encontrado) {
        std::cout << "Nenhum livro encontrado para o autor: " << autorProcurado << std::endl;
        std::cin.get();
    }
}

    // Função para pesquisar livros por título
void pesquisarLivrosPorTitulo() {
    Livro livro;
    bool encontrado = false;
    std::string tituloProcurado;

    std::cout << "Digite o nome do titulo para buscar: ";
    std::cin.ignore(); // Limpa qualquer caractere restante do buffer
    std::getline(std::cin, tituloProcurado);

    std::cout << "Pesquisando livros do titulo: " << tituloProcurado << std::endl;

    for (const auto &livro : livros) {
        if (livro.getTitulo() == tituloProcurado) {
            cout << "\n";
            livro.exibirInformacoes();
            encontrado = true;
            std::cout << "---------------------" << std::endl;
            std::cin.get();
        }
    }

    if (!encontrado) {
        std::cout << "Nenhum livro encontrado para o titulo: " << tituloProcurado << std::endl;
        std::cin.get();
    }
}

    // Função para pesquisar livros por gênero
void pesquisarLivrosPorGenero() {
    Livro livro;
    bool encontrado = false;
    std::string generoProcurado;

    std::cout << "Digite o nome do autor para buscar: ";
    std::cin.ignore(); // Limpa qualquer caractere restante do buffer
    std::getline(std::cin, generoProcurado);

    std::cout << "Pesquisando livros do genero: " << generoProcurado << std::endl;

    for (const auto &livro : livros) {
        if (livro.getGenero() == generoProcurado) {
            cout << "\n";
            livro.exibirInformacoes();
            encontrado = true;
            std::cout << "---------------------" << std::endl;
            std::cin.get();
        }
    }

    if (!encontrado) {
        std::cout << "Nenhum livro encontrado para o genero: " << generoProcurado << std::endl;
        std::cin.get();
    }
}

void emprestimoDeLivros() {
    string nome, contato;
    int isbn, quantidadeEmprestimo;
    bool encontrado = false;

    cout << "Digite seu nome: ";
    std::cin.ignore(); // Limpa qualquer caractere restante do buffer
    std::getline(std::cin, nome);
    cout << "Digite seu contato: ";
    std::cin.ignore(); // Limpa qualquer caractere restante do buffer
    std::getline(std::cin, contato);

    // procura o nome e contato do usuário digitado na lista de usuarios cadastrados

    for (Usuarios &usuario : usuarios) {
        if (usuario.getNome() == nome && usuario.getContato() == contato) {
            cout << "Usuario cadastrado, favor favor prosseguir com o emprestimo!";
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "Usuario nao encontrado no sistema, favor realizar o cadastro para emprestimo!";
        return;
    }

    cout << "------------------------\n";
    exibirLivrosCadastrados();
    
    cout << "Digite o ISBN do livro que deseja emprestar: ";
    cin >> isbn;

    // procura o ISBN digitado na lista livros
    for (Livro &livro : livros) {
        if (livro.getISBN() == isbn) {
            cout << "Digite a quantidade para emprestimo: ";
            cin >> quantidadeEmprestimo;
            if (quantidadeEmprestimo > livro.getQuantidade()) {
                cout << "Quantidade insuficiente em estoque!";
                return;
            }
            encontrado = true;
            livro.getQuantidade() -= quantidadeEmprestimo;
            cout << "Livro emprestado com sucesso";
        }
    }
    
    if (!encontrado) {
        cout << "Livro nao encontrado no sistema";
        return;
    }
}
