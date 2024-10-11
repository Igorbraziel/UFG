package Comparison_PExPOO.Part4_Task;

import java.util.Scanner;

public class Exercicio1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); 
        int numi = 0, numf = 0;
        double media, soma = 0;
        int qtde = 0, qtdePares = 0, qtdeImpares = 0;

        System.out.print("Entre o primeiro número: ");
        numi = sc.nextInt();

        System.out.print("Entre o segundo número: ");
        numf = sc.nextInt();

        if (numi > numf) {
            int num = numf;
            numf = numi;
            numi = num;
        }
        
        for (int i = numi; i <= numf ; i++) {
            qtde++;
            soma = soma + i;
            if ((i % 2) == 0) {
                qtdePares++;
            } else {
                qtdeImpares++;
            }
        }

        media = soma / qtde;

        System.out.println("Soma : " + soma + " - Média : " + media + 
        " -Qtde Pares : "+ qtdePares + " -Qtde Ímpares : " + qtdeImpares);

        sc.close();
    }
}
