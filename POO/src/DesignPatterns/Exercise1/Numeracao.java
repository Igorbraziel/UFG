package DesignPatterns.Exercise1;

public class Numeracao{
    private static Numeracao instance;
    private static int seq = 0;
    private int numero;

    private Numeracao() {
        numero = ++seq;
    }

    public static Numeracao getInstance(){
        if(instance == null){
            instance = new Numeracao();
        }
        return instance;
    }

    @Override
    public String toString() {
        return "Numeração " + numero;
    }
}
