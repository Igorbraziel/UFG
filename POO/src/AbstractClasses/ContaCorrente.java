package AbstractClasses;

public class ContaCorrente extends Conta {
    private double limite;

    public boolean validaConta() {
        if(numero > 100000)
            return false;
        else {
            return true;
        }
    }
}