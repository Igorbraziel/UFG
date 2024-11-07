package DesignPatterns.Observer.Example;

public class Main {
    public static void main(String[] args){
        Diet diet = new Diet(80.0);
        DietScale dietScale1 = new DietScale();
        DietScale dietScale2 = new DietScale();
        DietScale dietScale3 = new DietScale();

        diet.addObserver(dietScale1);
        diet.addObserver(dietScale2);
        diet.addObserver(dietScale3);

        diet.setWeight(80.0);
    }
}
