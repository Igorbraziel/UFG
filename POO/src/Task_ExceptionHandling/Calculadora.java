package Task_ExceptionHandling;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Calculadora {
    private Integer number1;
    private Integer number2;

    public Calculadora(Integer number1, Integer number2){
        this.number1 = number1;
        this.number2 = number2;
    }

    public Integer getNumber1() {
        return number1;
    }

    public void setNumber1(Integer number1) {
        this.number1 = number1;
    }

    public Integer getNumber2() {
        return number2;
    }

    public void setNumber2(Integer number2) {
        this.number2 = number2;
    }

    public Integer soma(){
        return number1 + number2;
    }

    public Integer subtracao(){
        return number1 - number2;
    }

    public Integer divisao(Scanner sc) throws InputMismatchException {
        boolean flag = true;
        while(true){
            try {
                if(flag == false){
                    System.out.print("Digite um novo número para ser o denominador da divisão: ");
                    return number1 / sc.nextInt();
                }
                return number1 / number2;
            } catch (ArithmeticException arithmeticException){
                System.out.println("Erro, impossível dividir por zero");
                flag = false;
            }
        }
        
    }

    public Integer multiplicacao(){
        return number1 * number2;
    }
}