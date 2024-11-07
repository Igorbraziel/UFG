package DesignPatterns.Observer.Example;

import java.util.Observer;
import java.util.Observable;
import java.util.List;
import java.util.ArrayList;

public class Diet extends Observable {
    private List<Observer> observersList = new ArrayList<>();
    private Double weight;

    public Diet(Double weight){
        this.weight = weight;
    }

    public Double getWeight(){
        return weight;
    }

    public void setWeight(Double weight){
        this.weight = weight;
        notifyObservers();
    }

    @Override
    public void addObserver(Observer o){
        observersList.add(o);
    }

    @Override
    public void deleteObserver(Observer o){
        observersList.remove(o);
    }

    @Override
    public int countObservers(){
        return observersList.size();
    }

    @Override
    public void notifyObservers(){
        for(Observer o: observersList){
            o.update(this, weight);
        }
    }
}
