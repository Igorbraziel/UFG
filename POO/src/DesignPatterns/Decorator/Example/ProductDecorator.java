package DesignPatterns.Decorator.Example;

public abstract class ProductDecorator implements ProductProtocol {
    public ProductProtocol product;

    public ProductDecorator(ProductProtocol product){
        this.product = product;
    }

    public abstract Double getPrice();

    public abstract String getName();
}
