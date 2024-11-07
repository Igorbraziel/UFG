package DesignPatterns.Exercise1;

public class TesteNumeracao {
    public static void main(String[] args) {
        for (int i = 0; i < 10; i++) {
            Numeracao num = Numeracao.getInstance();
            System.out.println(num);
        }
    }
}
