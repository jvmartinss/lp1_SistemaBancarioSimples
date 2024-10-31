Sistema Bancário em C++

Este projeto é uma implementação de um sistema bancário em C++, que permite criar clientes e contas bancárias, além de realizar operações básicas como depósito, saque e transferência.
Funcionalidades

    Criação de Clientes: Cada cliente possui um nome e um CPF.
    Criação de Contas Bancárias: Cada conta é associada a um cliente e possui um número de conta e um saldo.
    Depósito: Permite adicionar fundos a uma conta bancária.
    Saque: Permite a retirada de fundos de uma conta, desde que haja saldo suficiente.
    Transferência: Permite transferir fundos entre contas, incluindo a opção de dividir o valor entre duas contas de destino.
    Exibição de Informações: Mostra os detalhes do cliente e saldo atual da conta.

Estrutura das Classes
Classe Cliente

Representa um cliente do banco.

    Atributos:
        nome: Nome do cliente.
        cpf: CPF do cliente.
    Métodos:
        getNome(): Retorna o nome do cliente.
        getCpf(): Retorna o CPF do cliente.

Classe ContaBancaria

Representa uma conta bancária associada a um cliente.

    Atributos:
        numero: Número da conta bancária.
        saldo: Saldo da conta.
        titular: Cliente associado à conta.

    Métodos:
        depositar(double valor): Adiciona um valor ao saldo da conta.
        sacar(double valor): Subtrai um valor do saldo da conta, se houver saldo suficiente.
        transferir(double valor, ContaBancaria &destino): Transfere um valor para uma conta de destino.
        transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2): Transfere um valor dividido igualmente entre duas contas de destino.
        exibirSaldo(): Exibe o saldo atual da conta.
        exibirInformacoes(): Exibe informações do cliente titular e detalhes da conta.
