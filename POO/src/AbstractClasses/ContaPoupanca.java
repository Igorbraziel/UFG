package AbstractClasses;

public class ContaPoupanca extends Conta {
    private double juros;
    
    public boolean validaConta() {
        if (numero <= 100000)
            return false;
        else {
            return true;
        }
    }
}
