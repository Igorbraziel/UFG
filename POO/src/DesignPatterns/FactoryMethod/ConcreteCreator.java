package DesignPatterns.FactoryMethod;

public class ConcreteCreator extends Creator{
    public Product factoryMethod(String name, Double price){
        return new ConcreteProduct(name, price);
    }
}
