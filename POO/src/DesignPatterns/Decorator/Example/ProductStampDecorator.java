package DesignPatterns.Decorator.Example;

// Essa é uma subclasse de ProductDecorator, 
// ela é usada como invólucro para 
// as classes que implementam a interface ProductProtocol, 

// nesse exemplo, o unico componente concreto
// são os objetos da classe TShirt, logo,
// essa subclasse irá adicionar uma estampa a esses objetos em tempo de execução, 
// o preço das camisas aumentarão em 10 e no nome da camisa será
// acrescido a palavra (Estampado), 

public class ProductStampDecorator extends ProductDecorator {
    public ProductStampDecorator(ProductProtocol product){
        super(product);
    }

    @Override
    public Double getPrice(){
        return product.getPrice() + 10; // As Camisetas Estampadas tem um aumento de 10 Reais
    }

    @Override
    public String getName(){
        return product.getName() + " (Estampado)"; // As Camisetas estampadas tem um adicional no nome
    }

    @Override
    public String toString(){
        return "Nome: " + getName() + "\n" +
                "Preço: " + getPrice();
    }
}
