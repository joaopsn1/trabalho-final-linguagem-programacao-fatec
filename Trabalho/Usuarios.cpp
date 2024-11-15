#include <iostream>
#include <string>

using namespace std;

class Usuarios {
private:
    string nome;
    string endereco;
    string contato;

public:
    Usuarios() {

    }

public:
    Usuarios(const std::string &nome, const std::string &endereco, std::string &contato) : nome(nome), endereco(endereco), contato(contato) {}

    void exibirInformacoes() const {
        cout << "Nome: " << nome << endl;
        cout << "Endereco: " << endereco << endl;
        cout << "Contato: " << contato << endl;
    }

    string getNome() const {
        return nome;
    }

    string getEndereco() const {
        return endereco;
    }

    string getContato() const {
        return contato;
    }
};