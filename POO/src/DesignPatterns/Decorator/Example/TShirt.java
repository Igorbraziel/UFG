package DesignPatterns.Decorator.Example;

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
