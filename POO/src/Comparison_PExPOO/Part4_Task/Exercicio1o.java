package Comparison_PExPOO.Part4_Task;

import java.util.Scanner;

public class Exercicio1o {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); 
        int numi = 0, numf = 0, n;

        System.out.print("Entre o primeiro número: ");
        numi = sc.nextInt();

        System.out.print("Entre o segundo número: ");
        numf = sc.nextInt();

        Intervalo num = new Intervalo(numi,numf);

        System.out.println("Soma : " + num.soma());
        System.out.println("Média : " + num.media());
        System.out.println("Quantidade de Pares : " + num.qtdePares());
        System.out.println("Quantidade de Ímpares : " + num.qtdeImpares());
        System.out.println("Quantidade de números no intervalo: " + num.qtdeNumIntervalo() + "\n");

        System.out.print("Digite um número N para ver a soma dos N primeiros números: ");
        n = sc.nextInt();

        System.out.println("Soma dos " + n + " Primeiros números do intervalo: " + num.somaDosNPrimeiros(n));
        System.out.println("Diferença entre o número final e o inicial: " + num.diferenca());
        System.out.println("Informação sobre o intervalo: " + num);

        sc.close();
    }
}
