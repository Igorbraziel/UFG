package AbstractClasses;

public abstract class Conta {
    protected int numero;
    protected double saldo;
    
    public void saca(double valor) {
        saldo = saldo - valor;
    }

    public void deposita(double valor) {
        saldo = saldo + valor;
    }

    public void transfere(double valor,Conta destino){
        this.saca(valor);
        destino.deposita(valor);
    }

    public abstract boolean validaConta();
}
