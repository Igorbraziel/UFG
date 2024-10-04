public class Conta {
    private int numero;
    private String titular;
    private double saldo;

    public void setNumero(int numero){
        this.numero = numero;
    }

    public int getNumero(){
        return this.numero;
    }

    public void setTitular(String titular){
        this.titular = titular;
    }

    public String getTitular(){
        return this.titular;
    }

    public void setSaldo(double saldo){
        this.saldo = saldo;
    }

    public double getSaldo(){
        return this.saldo;
    }

    public double sacar(double valor){
        this.saldo -= valor;
        return valor; 
    }

    public double depositar(double valor){
        this.saldo += valor;
        return valor;
    }

    public void transferir(Conta contaDestino, double valor){
        this.sacar(valor);
        contaDestino.depositar(valor);
    }

    public String toString(){
        return "Numero da Conta: " + this.numero + "\n"
        + "Nome do Titular: " + this.titular + "\n"
        + "Saldo Atual da Conta: " + String.format("%.2f", this.saldo);
    }
}