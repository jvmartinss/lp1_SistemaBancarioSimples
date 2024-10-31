#include <iostream>
#include <string>
using namespace std;

    // Criação da classe Cliente que representa um cliente do banco
class Cliente {
private:  // Definindo como privado os atributos (nome e cpf) da classe Cliente
    string nome;
    string cpf;

public:
    // Construtor que recebe o nome e o cpf do cliente ambos string como parâmetros
    Cliente(string nome, string cpf) : nome(nome), cpf(cpf) {}

    // Métodos getters para acessar os atributos privados
    string getNome() const { return nome; }
    string getCpf() const { return cpf; }
};
    // Criação da classe Conta que representa uma conta bancária
class ContaBancaria {
private: // Definindo como privado os atributos (saldo e cliente) da classe ContaBancaria
    int numero;
    double saldo;
    Cliente titular;

public:
    // Construtor que recebe o número, o saldo e o cliente da conta bancária
    ContaBancaria(int numero, Cliente titular, double saldo = 0.0) //saldo padrão como 0.0
        : numero(numero), saldo(saldo), titular(titular) {}

    // Método para depositar que aumenta o saldo da conta com um valor positivo fornecido.
    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
            cout << "Depósito de R$ " << valor << " realizado na conta " << numero << endl;
        } else {
            cout << "Valor de depósito inválido!" << endl;
        }
    }

    // Método para sacar que diminui o saldo da conta com um valor positivo fornecido.
    void sacar(double valor) {
        if (valor > 0 && saldo >= valor) {
            saldo -= valor;
            cout << "Saque de R$ " << valor << " realizado na conta " << numero << endl;
        } else {
            cout << "Saldo insuficiente ou valor inválido para saque!" << endl;
        }
    }

    // Método para transferir (um destino) que diminui o saldo da conta de origem com um valor positivo fornecido.
    void transferir(double valor, ContaBancaria &destino) {
        if (valor > 0 && saldo >= valor) {
            saldo -= valor;
            destino.depositar(valor);
            cout << "Transferido: R$ " << valor << " da conta " << numero << " para a conta " << destino.numero << endl;
        } else {
            cout << "Saldo insuficiente ou valor inválido para transferência!" << endl;
        }
    }

    // Método para transferir (dois destinos) que diminui o saldo da conta de origem um valor positivo fornecido e transfere para duas contas de destino.
    void transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2) {
        double metade = valor / 2;
        if (valor > 0 && saldo >= valor) {
            saldo -= valor;
            destino1.depositar(metade);
            destino2.depositar(metade);
            cout << "Transferido: R$ " << metade << " para cada conta (" << destino1.numero << " e " << destino2.numero << ") da conta " << numero << endl;
        } else {
            cout << "Saldo insuficiente ou valor inválido para transferência!" << endl;
        }
    }

    // Método para exibir saldo da conta
    void exibirSaldo() const {
        cout << "Saldo atual da conta " << numero << ": R$ " << saldo << endl;
    }

    // Método para exibir informações da conta e titular 
    void exibirInformacoes() const {
        cout << "Titular: " << titular.getNome() << ", CPF: " << titular.getCpf() << endl;
        cout << "Número da Conta: " << numero << ", Saldo: R$ " << saldo << endl;
    }
};

int main() {
    // Criação dos clientes
    Cliente cliente1("Ana", "111.111.111-11");
    Cliente cliente2("Bruno", "222.222.222-22");
    Cliente cliente3("Carla", "333.333.333-33");

    // Criação das contas bancárias com saldos iniciais
    ContaBancaria conta1(1001, cliente1, 1000.0);
    ContaBancaria conta2(1002, cliente2);
    ContaBancaria conta3(1003, cliente3);

    // Exibe o saldo inicial da conta de Ana
    conta1.exibirSaldo();

    // Ana transfere R$200 para Bruno
    conta1.transferir(200.0, conta2);

    // Ana transfere R$300 divididos entre Bruno e Carla
    conta1.transferir(300.0, conta2, conta3);

    // Exibição dos saldos finais
    cout << endl;
    conta1.exibirInformacoes();
    conta2.exibirInformacoes();
    conta3.exibirInformacoes();

    return 0;
}
