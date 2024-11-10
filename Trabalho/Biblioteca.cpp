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
void cadastrarUsuario()
{
    string nome, endereco, contato;

    cout << "\nNome: ";
    cin >> nome;
    cout << "Endereco: ";
    cin >> endereco;
    cout << "Contato: ";
    cin >> contato;

    usuarios.emplace_back(nome, endereco, contato); // Adicionando novo objeto Usuarios a Lista
    cout << "Usuario cadastrado com sucesso!" << endl;
}

// Exibir lista de usuários cadastrados
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
    cin >> titulo;
    cout << "Autor: ";
    cin >> autor;
    cout << "ISBN: ";
    cin >> isbn;
    cout << "Genero: ";
    cin >> genero;
    cout << "Quantidade: ";
    cin >> quantidade;

    livros.emplace_back(titulo, autor, isbn, genero, quantidade); // Adicionando novo objeto Livros a Lista
    cout << "Livro cadastrado com sucesso!" << endl;
}

// Exibir lista de usuários cadastrados
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

    livros.remove_if([isbnParaRemover](const Livro& livro){ 
        return livro.getISBN() == isbnParaRemover; 
    });

    if (livros.size() < afterSize)
    {
        cout << "Livro removido com sucesso!\n";
    } else {
        cout << "Livro não cadastrado no sistema!\n";
    }
}