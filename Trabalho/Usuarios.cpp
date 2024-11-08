#include <iostream>
#include <string>

using namespace std;

string nome;
string endereco;
string contato;

class Usuarios
{
public:
    std::string nome;
    std::string endereco;
    std::string contato;

    Usuarios(const std::string &nome, const std::string &endereco, std::string &contato) : nome(nome), endereco(endereco), contato(contato) {}

    void exibirInformacoes() const
    {
        cout << "Nome: " << nome << endl;
        cout << "Endereço: " << endereco << endl;
        cout << "Contato: " << contato << endl;
    }
};