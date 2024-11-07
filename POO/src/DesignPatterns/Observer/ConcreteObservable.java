package DesignPatterns.Observer;

import java.util.Observable;
import java.util.Observer;
import java.util.List;
import java.util.ArrayList;

public class ConcreteObservable extends Observable {
    private List<Observer> observersList = new ArrayList<>();
    private Boolean subjectState;

    public Boolean getSubjectState() {
        return subjectState;
    }

    public void setSubjectState(Boolean subjectState) {
        this.subjectState = subjectState;
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
        for(Observer o : observersList){
            o.update(this, subjectState);
        }
    }
}
