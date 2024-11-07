package DesignPatterns.Observer;

import java.util.Observable;
import java.util.Observer;

public class ConcreteObserver implements Observer{
    private Boolean subjectState;

    @Override
    public void update(Observable subject, Object subjectState) {
        this.subjectState = (Boolean) subjectState;
    }
}
