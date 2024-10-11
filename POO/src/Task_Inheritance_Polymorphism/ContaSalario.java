package Task_Inheritance_Polymorphism;

public class ContaSalario extends ContaCorrente {
    public double sacar(double valor){
        this.setSaldo(this.getSaldo() - (valor + 0.01));
        return valor; 
    }

    public double depositar(double valor){
        this.setSaldo(this.getSaldo() + (valor - 0.01));
        return valor;
    }
}
