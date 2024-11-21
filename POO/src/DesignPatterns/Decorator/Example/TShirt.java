package DesignPatterns.Decorator.Example;

// Essa é a classe concreta TShirt, que implementa 
// a interface ProductProtocol 

// tem os atributos: preço e nome
// ela tem o comportamento base

// Os Decorators concretos podem envolver objetos dessa classe 
// e adicionar comportamentos em tempo de execução

public class TShirt implements ProductProtocol {
    private Double price;
    private String name;

    public TShirt(Double price, String name){
        this.price = price;
        this.name = name;
    }

    public Double getPrice(){
        return price;
    }

    public String getName(){
        return name;
    }

    @Override
    public String toString(){
        return "Nome: " + name + "\n" +
                "Preço: " + price;
    }
}
