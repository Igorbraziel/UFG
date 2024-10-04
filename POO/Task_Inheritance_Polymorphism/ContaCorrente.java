public class ContaCorrente extends Conta{
    public double sacar(double valor){
        this.setSaldo(this.getSaldo() - (valor + 0.05));
        return valor; 
    }

    public double depositar(double valor){
        this.setSaldo(this.getSaldo() + (valor - 0.05));
        return valor;
    }
}
