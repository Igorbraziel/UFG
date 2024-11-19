package DesignPatterns.Decorator.Example;

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
        return product.getName() + " (Estampado)";
    }

    @Override
    public String toString(){
        return "Nome: " + getName() + "\n" +
                "Preço: " + getPrice();
    }
}
