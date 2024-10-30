package Task_ExceptionHandling;


import java.util.Locale;
import java.util.Scanner;
import java.util.InputMismatchException;


public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);

        try{
            System.out.print("Digite o primeiro número: ");
            int number1 = sc.nextInt();

            System.out.print("Digite o segundo número: ");
            int number2 = sc.nextInt();

            Calculadora calculator = new Calculadora(number1, number2);

            System.out.println("Resultado da soma: " + calculator.soma());
            System.out.println("Resultado da subtração: " + calculator.subtracao());
            System.out.println("Resultado da divisão: " + calculator.divisao(sc));
            System.out.println("Resultado da multiplicação: " + calculator.multiplicacao());
        } catch(InputMismatchException inputMismatchException){
            System.out.println("Incompatibilidade na entrada de dados");
            System.out.println("FIM DO PROGRAMA!");
        }

        sc.close();
    }
}
