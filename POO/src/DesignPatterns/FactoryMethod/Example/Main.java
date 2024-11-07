package DesignPatterns.FactoryMethod.Example;

import java.util.Locale;
import java.util.List;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args){
        Locale.setDefault(Locale.US);
        Factory personFactory = new PersonFactory();
        List<Person> peopleList = new ArrayList<>();
        peopleList.add(personFactory.createPerson("Igor", "male"));
        peopleList.add(personFactory.createPerson("Nine", "female"));
        for(Person person : peopleList){
            System.out.println(person);
        }
    }
}
