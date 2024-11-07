package DesignPatterns.FactoryMethod.Example;

public class PersonFactory extends Factory {
    public Person createPerson(String name, String gender){
        if(gender.equals("male")){
            return new Man(name, gender);
        } 
        return new Woman(name, gender);
    }
}
