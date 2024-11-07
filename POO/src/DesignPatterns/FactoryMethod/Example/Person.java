package DesignPatterns.FactoryMethod.Example;

public abstract class Person {
    public String name;
    public String gender;

    @Override
    public String toString(){
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append("Name: " + name + '\n');
        stringBuilder.append("Gender: " + gender);
        return stringBuilder.toString();
    }
}
