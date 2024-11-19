#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "Usuarios.cpp"
#include "Livro.cpp"
#include <ctime>
#include <map>

using namespace std;

list<Usuarios> usuarios;
list<Livro> livros;
list<pair<Usuarios, Livro>> livrosPorUsuario;

int quantidadeEmprestimo, quantidadeDevolucao, isbnEmprestimo, isbnDevolucao;

Usuarios usuarioSelecionado;
Livro livroSelecionado;

// Cadastrar Usuários na biblioteca
void cadastrarUsuario() {
    string nome, endereco, contato;

    cout << "\nNome: ";
    std::cin.ignore();
    std::getline(std::cin, nome);
    cout << "Endereco: ";
    std::getline(std::cin, endereco);
    cout << "Contato: ";
    std::getline(std::cin, contato);

    usuarios.emplace_back(nome, endereco, contato); // Adicionando novo objeto Usuarios a Lista
    cout << "Usuario " << nome << " cadastrado com sucesso!" << endl;
}

// Exibir lista de usuários cadastrados
void exibirUsuariosCadastrados() {
    cout << "\n.:: USUARIOS CADASTRADOS ::.\n";
    if (usuarios.empty()) {
        cout << "Nenhum usuario cadastrado" << endl;
        cout << "------------------------\n";
        return;
    }

    for (const Usuarios &usuario : usuarios) {
        usuario.exibirInformacoes();
        cout << "------------------------\n";
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
    cout << "Livro " << titulo << " cadastrado com sucesso!" << endl;
}

// Exibir lista de usuários cadastrados
void exibirLivrosCadastrados() {
    cout << "\n.:: LIVROS CADASTRADOS ::.\n";
    if (livros.empty()) {
        cout << "Nenhum livro cadastrado" << endl;
        return;
    }

    for (const Livro &livro : livros) {
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

    if (livros.size()< afterSize) {
        cout << "Livro " << livro.getTitulo() << " removido com sucesso!\n";
        cout << "------------------------\n";
    } else {
        cout << "Livro nao cadastrado no sistema!\n";
        cout << "------------------------\n";
    }
}

void editarQuantidade() {
    int quantidadeAdicionarRetirar, escolha, isbn;
    bool encontrado = false;

    cout << "Digite o ISBN do livro para procura: ";
    cin >> isbn;
    
    for(Livro &livro : livros) {
        if (livro.getISBN() == isbn) {
            livro.exibirInformacoes();
            encontrado = true;
            cout << "Digite a quantidade para adicionar/retirar: ";
            cin >> quantidadeAdicionarRetirar;
            cout << "[1] Adicionar\n";
            cout << "[2] Retirar\n";
            cout << "Digite a opcao: ";
            cin >> escolha;

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
                cout << "------------------------\n";
            }
        }
    }

    if (!encontrado) {
        cout << "Livro nao encontrado!" << endl;
        cout << "------------------------\n";
        return;
    }
}

// Função para pesquisar livros por autor
void pesquisarLivrosPorAutor() {
    Livro livro;
    bool encontrado = false;
    std::string autorProcurado;

    std::cout << "Digite o nome do autor para buscar: ";
    std::cin.ignore();  // Limpa qualquer caractere restante do buffer
    std::getline(std::cin, autorProcurado);

    std::cout << "Pesquisando livros do autor: " << autorProcurado << std::endl;

    for (const Livro &livro : livros) {
        if (livro.getAutor() == autorProcurado) {
            cout << "\n";
            livro.exibirInformacoes();
            encontrado = true;
            std::cout << "------------------------" << std::endl;
            std::cin.get();
        }
    } 

    if (!encontrado) {
        std::cout << "Nenhum livro encontrado para o autor: " << autorProcurado << std::endl;
        cout << "------------------------\n";
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
            std::cout << "------------------------" << std::endl;
            std::cin.get();
        }
    }

    if (!encontrado) {
        std::cout << "Nenhum livro encontrado para o titulo: " << tituloProcurado << std::endl;
        cout << "------------------------\n";
        std::cin.get();
    }
}

    // Função para pesquisar livros por gênero
void pesquisarLivrosPorGenero() {
    Livro livro;
    bool encontrado = false;
    std::string generoProcurado;

    std::cout << "Digite o nome do genero para buscar: ";
    std::cin.ignore(); // Limpa qualquer caractere restante do buffer
    std::getline(std::cin, generoProcurado);

    std::cout << "Pesquisando livros do genero: " << generoProcurado << std::endl;

    for (const auto &livro : livros) {
        if (livro.getGenero() == generoProcurado) {
            cout << "\n";
            livro.exibirInformacoes();
            encontrado = true;
            std::cout << "------------------------" << std::endl;
            std::cin.get();
        }
    }

    if (!encontrado) {
        std::cout << "Nenhum livro encontrado para o genero: " << generoProcurado << std::endl;
        cout << "------------------------\n";
        std::cin.get();
    }
}

void emprestimoDeLivros() {
    string nome, contato;
    bool encontradoUsuario = false;
    bool encontradoLivro = false;

    time_t timer = time(nullptr); // Obtem o tempo atual em segundos
    tm* horarioLocal = localtime(&timer); // Converte para o formato local
    time(&timer); // Obtem informações de data e hora
    int diaEmprestimo = horarioLocal->tm_mday;
    int mesEmprestimo = horarioLocal->tm_mon + 1;
    int anoEmprestimo = horarioLocal->tm_year + 1900;

    cout << "Digite seu nome: ";
    std::cin.ignore(); // Limpa qualquer caractere restante do buffer
    std::getline(std::cin, nome);
    cout << "Digite seu contato: ";
    std::getline(std::cin, contato);

    // procura o nome e contato do usuário digitado na lista de usuarios cadastrados
    Usuarios usuarioSelecionado;
    for (Usuarios &usuario : usuarios) {
        if (usuario.getNome() == nome && usuario.getContato() == contato) {
            cout << "Usuario cadastrado, favor prosseguir com o emprestimo!\n";
            usuarioSelecionado = usuario;
            encontradoUsuario = true;
        }
    }

    if (!encontradoUsuario) {
        cout << "Usuario nao encontrado no sistema, favor realizar o cadastro para emprestimo!\n";
        cout << "------------------------\n";
        return;
    }

    cout << "------------------------\n";
    exibirLivrosCadastrados();
    
    cout << "Digite o ISBN do livro que deseja emprestar: ";
    cin >> isbnEmprestimo;

    // procura o ISBN digitado na lista livros
    Livro livroSelecionado;
    for (Livro &livro : livros) {
        if (livro.getISBN() == isbnEmprestimo) {
            cout << "Digite a quantidade para emprestimo: ";
            cin >> quantidadeEmprestimo;
            if (quantidadeEmprestimo > 1) {
                cout << "Nao e possivel emprestar mais de 1 livro do mesmo titulo, favor emprestar livros diferentes!\n";
                cout << "------------------------\n";
                return;
            }
            encontradoLivro = true;
            livro.getQuantidade() -= quantidadeEmprestimo;
            livroSelecionado = livro; 
        }
    }
    
    if (!encontradoLivro) {
        cout << "Livro nao encontrado no sistema\n";
        cout << "------------------------\n";
        return;
    }

    livrosPorUsuario.emplace_back(usuarioSelecionado, livroSelecionado);
    cout << "\nLivro emprestado com sucesso na Data: " << diaEmprestimo << "/" << mesEmprestimo << "/" << anoEmprestimo << endl;
    cout << "Prazo para devolucao de 7 dias\n" << endl;
    cout << "------------------------\n";
}

void exibirEmprestimos() {
    cout << "\n.:: LISTA DE EMPRESTIMOS ::.\n";
    if (livrosPorUsuario.empty()) {
        cout << "Nenhum livro emprestado!\n" << endl;
        cout << "------------------------\n";
        return;
    }
    
    for (const auto& emprestimo : livrosPorUsuario) {
        const Usuarios& usuario = emprestimo.first;
        Livro livro = emprestimo.second;
        cout << "Nome: " << usuario.getNome() << "\n";
        cout << "Contato: " << usuario.getContato() << "\n";
        cout << "Livro: " << livro.getTitulo() << "\n";
        cout << "ISBN: " << livro.getISBN() << "\n";
        cout << "Quantidade: " << quantidadeEmprestimo << "\n";
        cout << "------------------------\n";
    }
}

void devolucaoDeLivros(){
    string nome, contato;
    bool encontradoEmprestimo = false;

    time_t timer = time(nullptr); // Obtem o tempo atual em segundos
    tm* horarioLocal = localtime(&timer); // Converte para o formato local
    time(&timer); // Obtem informações de data e hora
    int diaDevolucao = horarioLocal->tm_mday;
    int mesDevolucao = horarioLocal->tm_mon + 1;
    int anoDevolucao = horarioLocal->tm_year + 1900;

    cout << "Emprestimos cadastrados\n";
    exibirEmprestimos();

    cout << "Digite seu nome: ";
    std::cin.ignore(); // Limpa qualquer caractere restante do buffer
    std::getline(std::cin, nome);
    cout << "Digite seu contato: ";
    std::getline(std::cin, contato);
    
    cout << "Digite o ISBN do livro que deseja devolver: ";
    cin >> isbnDevolucao;

    // procura o nome e contato do usuário digitado na lista de emprestimos
    for (auto it = livrosPorUsuario.begin(); it != livrosPorUsuario.end(); ++it) {
        const Usuarios& usuario = it->first;
        Livro& livro = it->second;

        if (usuario.getNome() == nome && usuario.getContato() == contato && isbnDevolucao == livro.getISBN()) {
            cout << "Digite a quantidade para devolver: ";
            cin >> quantidadeDevolucao;

            if (quantidadeDevolucao > 1) {
                cout << "Quantidade invalida!\n";
                cout << "------------------------\n";
                return;
            }

            for (Livro &livro : livros) {
                livro.getQuantidade() += quantidadeDevolucao;
            }
            
            encontradoEmprestimo = true;
            // Remover o empréstimo da lista se a quantidade emprestada for 0
            livrosPorUsuario.erase(it);
            cout << "Livro devolvido com sucesso na data " << diaDevolucao << "/" << mesDevolucao << "/" << anoDevolucao << endl;
            cout << "------------------------\n";
            return;
        }
    }

    if (!encontradoEmprestimo) {
        cout << "Emprestimo nao encontrado para o usuario e ISBN fornecidos.\n";
        cout << "------------------------\n";
        return;
    }
}

void livroMaisEmprestado() {
    if (livrosPorUsuario.empty()) {
        cout << "Nenhum livro foi emprestado ainda!\n";
        cout << "------------------------\n";
        return;
    }

    // Mapeia ISBNs para a quantidade de empréstimos
    map<int, int> contagemEmprestimos;

    // Conta o número de vezes que cada ISBN foi emprestado
    for (const auto &emprestimo : livrosPorUsuario) {
        int isbn = emprestimo.second.getISBN();
        contagemEmprestimos[isbn]++;
    }

    // Encontra o ISBN com o maior número de empréstimos
    int isbnMaisEmprestado = 0;
    int maiorQuantidade = 0;
    for (const auto &item : contagemEmprestimos) {
        if (item.second > maiorQuantidade) {
            maiorQuantidade = item.second;
            isbnMaisEmprestado = item.first;
        }
    }

    // Busca o livro correspondente pelo ISBN
    for (const Livro &livro : livros) {
        if (livro.getISBN() == isbnMaisEmprestado) {
            cout << "\n.:: LIVRO MAIS EMPRESTADO ::.\n";
            livro.exibirInformacoes();
            cout << "Quantidade de emprestimos: " << maiorQuantidade << "\n";
            cout << "------------------------\n";
            return;
        }
    }

    cout << "Erro: Livro mais emprestado nao encontrado no sistema!\n";
    cout << "------------------------\n";
}

void usuarioComMaisEmprestimos() {
    if (livrosPorUsuario.empty()) {
        cout << "Nenhum empréstimo foi realizado ainda!\n";
        cout << "------------------------\n";
        return;
    }

    // Mapeia o nome do usuário para a quantidade de empréstimos
    map<string, int> contagemEmprestimos;

    // Conta o número de empréstimos por usuário
    for (const auto &emprestimo : livrosPorUsuario) {
        string nomeUsuario = emprestimo.first.getNome();
        contagemEmprestimos[nomeUsuario]++;
    }

    // Encontra o usuário com o maior número de empréstimos
    string usuarioMaisEmprestimos;
    int maiorQuantidade = 0;
    for (const auto &item : contagemEmprestimos) {
        if (item.second > maiorQuantidade) {
            maiorQuantidade = item.second;
            usuarioMaisEmprestimos = item.first;
        }
    }

    // Busca o usuário correspondente e exibe as informações
    for (const Usuarios &usuario : usuarios) {
        if (usuario.getNome() == usuarioMaisEmprestimos) {
            cout << "\n.:: USUARIO COM MAIS EMPRESTIMOS ::.\n";
            usuario.exibirInformacoes();
            cout << "Quantidade de emprestimos: " << maiorQuantidade << "\n";
            cout << "------------------------\n";
            return;
        }
    }

    cout << "Erro: Usuario com mais empréstimos não encontrado no sistema!\n";
    cout << "------------------------\n";
}

