package Part4_Task;

public class Intervalo {
    public int numi;
    public int numf;
    
    public Intervalo (int numi, int numf) {
        if (numi < numf) {
            this.numi = numi;
            this.numf = numf;
        }
        else{
            this.numi = numf;
            this.numf = numi;
        }
    }

    public double soma() {
        double soma = 0;
        for (int i = numi; i < numf + 1; i++) {
            soma = soma + i;
        }
        return soma;
    }

    public double media() {
        return soma()/(numf-numi+1);
    }

    public int qtdePares() {
        int qtde = 0;
        for (int i = numi; i < numf + 1; i++) {
            if ((i % 2) == 0)
            qtde++;
        }
        return qtde;
    }

    public int qtdeImpares() {
        int qtde = 0;
        for (int i = numi; i < numf + 1; i++) {
            if ((i % 2) > 0)
            qtde++;
        }
        return qtde;
    }

    public int qtdeNumIntervalo(){
        int qtde = 0;
        for(int i = numi; i <= numf; i++){
            qtde++;
        }
        return qtde;
    }

    public int somaDosNPrimeiros(int n){
        int soma = 0, tempNumi = numi;
        for(int i = 0; i < n; i++){
            soma += tempNumi;
            tempNumi++;
            if(tempNumi > numf){
                return soma;
            }
        }
        return soma;
    }

    public int diferenca(){
        return numf - numi;
    }

    public String toString(){
        return "Intervalo entre " + numi + " e " + numf;
    }
}
    
    
