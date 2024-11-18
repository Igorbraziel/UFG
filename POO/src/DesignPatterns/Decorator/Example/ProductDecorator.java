package DesignPatterns.Decorator.Example;

public abstract class ProductDecorator implements ProductProtocol {
    public ProductProtocol product;

    public ProductDecorator(ProductProtocol product){
        this.product = product;
    }

    public Double getPrice(){
        return product.getPrice();
    }

    public String getName(){
        return product.getName();
    }
}
