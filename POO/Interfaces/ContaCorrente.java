package Interfaces;

public class ContaCorrente extends Conta implements Tributavel {
    private double limite;

    public boolean validaConta() {
        if (numero > 100000)
            return false;
        else {
            return true;
        }
    }
    
    public double calculaTributos() {
        return saldo * 0.01;
    }
}