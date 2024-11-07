#include <iostream>
#include <string>

using namespace std;

string titulo;
string autor;
int isbn;
string genero;
int quantidade;

class Livro
{
public:
    std::string titulo;
    std::string autor;
    int isbn;
    std::string genero;
    int quantidade;

    Livro(const std::string &titulo, const std::string &autor, int isbn, std::string &genero, int quantidade) : titulo(titulo), autor(autor), isbn(isbn), genero(genero), quantidade(quantidade) {}

    void exibirInformacoes() const

    {
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Genero: " << genero << endl;
        cout << "Quantidade: " << quantidade << endl;
    }
};