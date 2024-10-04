public class Cadastro {
    public static void main(String[] args) {
        Conta contaCorrente = new ContaCorrente();
        Conta contaPoupanca = new ContaPoupanca();

        contaCorrente.setNumero(110);
        contaCorrente.setTitular("Nome do Titular da Conta Corrente");
        contaCorrente.setSaldo(4567.80);

        contaPoupanca.setNumero(77);
        contaPoupanca.setTitular("Nome do Titular da Conta Poupanca");
        contaPoupanca.setSaldo(4567.80);

        contaCorrente.depositar(1000);
        System.out.println("Dados da Conta Corrente Apos Deposito:");
        System.out.println(contaCorrente);
        System.out.println("-------------------------------------------------------------------");

        contaCorrente.sacar(500);
        System.out.println("Dados da Conta Corrente Apos Saque:");
        System.out.println(contaCorrente);
        System.out.println("-------------------------------------------------------------------");

        contaPoupanca.depositar(1000);
        System.out.println("Dados da Conta Poupanca Apos Deposito:");
        System.out.println(contaPoupanca);
        System.out.println("-------------------------------------------------------------------");

        contaPoupanca.sacar(500);
        System.out.println("Dados da Conta Poupanca Apos Saque:");
        System.out.println(contaPoupanca);
        System.out.println("-------------------------------------------------------------------");

        ((ContaPoupanca) contaPoupanca).atualizarSaldo(20.0 / 100.0);
        System.out.println("Dados da Conta Poupanca Apos Atualizar Saldo:");
        System.out.println(contaPoupanca);
        System.out.println("-------------------------------------------------------------------");

        // Altere a declaração das contas para seus tipos próprios, retire o casting e veja os resultados.
        
        ContaCorrente novaContaCorrente = (ContaCorrente) contaCorrente;
        ContaPoupanca novaContaPoupanca = (ContaPoupanca) contaPoupanca;

        novaContaCorrente.setNumero(110);
        novaContaCorrente.setTitular("Nome do Titular da Nova Conta Corrente");
        novaContaCorrente.setSaldo(4567.80);

        novaContaPoupanca.setNumero(77);
        novaContaPoupanca.setTitular("Nome do Titular da Nova Conta Poupanca");
        novaContaPoupanca.setSaldo(4567.80);

        novaContaCorrente.depositar(1000);
        System.out.println("Dados da Nova Conta Corrente Apos Deposito:");
        System.out.println(novaContaCorrente);
        System.out.println("-------------------------------------------------------------------");

        novaContaCorrente.sacar(500);
        System.out.println("Dados da Nova Conta Corrente Apos Saque:");
        System.out.println(novaContaCorrente);
        System.out.println("-------------------------------------------------------------------");

        novaContaPoupanca.depositar(1000);
        System.out.println("Dados da Nova Conta Poupanca Apos Deposito:");
        System.out.println(novaContaPoupanca);
        System.out.println("-------------------------------------------------------------------");

        novaContaPoupanca.sacar(500);
        System.out.println("Dados da Nova Conta Poupanca Apos Saque:");
        System.out.println(novaContaPoupanca);
        System.out.println("-------------------------------------------------------------------");

        novaContaPoupanca.atualizarSaldo(20.0 / 100.0);
        System.out.println("Dados da Nova Conta Poupanca Apos Atualizar Saldo:");
        System.out.println(novaContaPoupanca);
        System.out.println("-------------------------------------------------------------------");

//      Crie outras contas dos dois tipos e use o método transferir entre elas. Execute e veja os resultados.
//      Observe que o método transferir também precisa aplicar as taxas de depósito e saque nas devidas
//      contas.

        ContaCorrente outraContaCorrente = new ContaCorrente();
        ContaPoupanca outraContaPoupanca = new ContaPoupanca();

        outraContaCorrente.setNumero(210);
        outraContaCorrente.setTitular("Nome do Titular da Outra Conta Corrente");
        outraContaCorrente.setSaldo(9000);

        outraContaPoupanca.setNumero(277);
        outraContaPoupanca.setTitular("Nome do Titular da Outra Conta Poupanca");
        outraContaPoupanca.setSaldo(9000);

        outraContaCorrente.transferir(outraContaPoupanca, 5000);

        System.out.println("Dados das Contas Apos Transferencia:");
        System.out.println(outraContaCorrente);
        System.out.println("-------------------------------------------------------------------");
        System.out.println(outraContaPoupanca);
        System.out.println("-------------------------------------------------------------------");

        // Na classe Cadastro, declare contas do tipo ContaSalario, configure seus dados e invoque os
        // métodos sacar, depositar e transferir avaliando os resultados.

        ContaSalario contaSalario1 = new ContaSalario();
        ContaSalario contaSalario2 = new ContaSalario();

        contaSalario1.setNumero(520);
        contaSalario1.setTitular("Nome do Titular da Conta Salario 1");
        contaSalario1.setSaldo(19000);

        contaSalario2.setNumero(12);
        contaSalario2.setTitular("Nome do Titular da Conta Salario 2");
        contaSalario2.setSaldo(34000.450);

        contaSalario1.depositar(1000);
        System.out.println("Dados da Conta Salario 1 Apos Deposito:");
        System.out.println(contaSalario1);
        System.out.println("-------------------------------------------------------------------");

        contaSalario1.sacar(500);
        System.out.println("Dados da Conta Salario 1 Apos Saque:");
        System.out.println(contaSalario1);
        System.out.println("-------------------------------------------------------------------");

        contaSalario2.depositar(1000);
        System.out.println("Dados da Conta Salario 2 Apos Deposito:");
        System.out.println(contaSalario2);
        System.out.println("-------------------------------------------------------------------");

        contaSalario2.sacar(500);
        System.out.println("Dados da Conta Salario 2 Apos Saque:");
        System.out.println(contaSalario2);
        System.out.println("-------------------------------------------------------------------");

        contaSalario1.transferir(contaSalario2, 5000);
        System.out.println("Dados das Contas Salario Apos Transferencia:");
        System.out.println(contaSalario1);
        System.out.println("-------------------------------------------------------------------");
        System.out.println(contaSalario2);
        System.out.println("-------------------------------------------------------------------");

        // Faça transferência entre contas de tipos diferentes e avalie os resultados. Veja se os cálculos das
        // taxas estão corretos.

        contaSalario2.transferir(novaContaCorrente, 5000);
        System.out.println("Dados das Contas de tipos diferentes Apos Transferencia:");
        System.out.println(contaSalario2);
        System.out.println("-------------------------------------------------------------------");
        System.out.println(novaContaCorrente);
        System.out.println("-------------------------------------------------------------------");
    }
}
