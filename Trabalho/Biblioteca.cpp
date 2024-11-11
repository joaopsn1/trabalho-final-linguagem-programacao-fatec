#include <iostream>
#include <string>
#include <list>
#include "Usuarios.cpp"
#include "Livro.cpp"
#include <algorithm>

using namespace std;

list<Usuarios> usuarios;
list<Livro> livros;

//Cadastrar Usuários na biblioteca
void cadastrarUsuario()
{
    cout << "\nNome: ";
    cin >> nome;
    cout << "Endereco: ";
    cin >> endereco;
    cout << "Contato: ";
    cin >> contato;

    usuarios.emplace_back(nome, endereco, contato); // Adicionando novo objeto Usuarios a Lista
    cout << "Usuario cadastrado com sucesso!" << endl;
}

//Exibir lista de usuários cadastrados
void exibirUsuariosCadastrados()
{
    if (usuarios.empty())
    {
        cout << "Nenhum usuario cadastrado" << endl;
        return;
    }

    for (const auto &usuario : usuarios)
    {
        usuario.exibirInformacoes();
    }
}

void cadastrarLivro()
{
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

//Exibir lista de usuários cadastrados
void exibirLivrosCadastrados()
{
    cout << "\n.:: LIVROS CADASTRADOS ::.\n";
    if (livros.empty())
    {
        cout << "Nenhum livro cadastrado" << endl;
        return;
    }

    for (const auto &livro : livros)
    {
        livro.exibirInformacoes();
        cout << "------------------------\n";
    }
}

void removerLivrosPorISBN()
{
    Livro livro;
    int isbnParaRemover;
    cout << "\nDigite o ISBN do livro para remove-lo: ";
    cin >> isbnParaRemover;

    int afterSize = livros.size();

    livros.remove_if([isbnParaRemover](const Livro &livro)
                     { return livro.getISBN() == isbnParaRemover; });

    if (livros.size() < afterSize)
    {
        cout << "Livro removido com sucesso!\n";
    }
    else
    {
        cout << "Livro não cadastrado no sistema!\n";
    }
}

//std::vector<Livro> biblioteca;


// Função para pesquisar livros por autor
void pesquisarLivrosPorAutor() {
    Livro livro;
    bool encontrado = false;
    std::string autorProcurado;

    std::cout << "Digite o nome do autor para buscar: ";
    std::cin.ignore();  // Limpa qualquer caractere restante do buffer
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

