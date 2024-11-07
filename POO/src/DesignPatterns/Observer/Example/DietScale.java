package DesignPatterns.Observer.Example;

import java.util.Observer;
import java.util.Observable;

public class DietScale implements Observer {
    @Override
    public void update(Observable o, Object obj){
        if((Double) obj >= 100){
            System.out.println("You have surpassed the system weight limit!");
        }
    }
}
