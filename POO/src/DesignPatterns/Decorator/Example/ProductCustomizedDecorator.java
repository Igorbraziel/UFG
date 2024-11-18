package DesignPatterns.Decorator.Example;

public class ProductCustomizedDecorator extends ProductDecorator {
    public ProductCustomizedDecorator(ProductProtocol product){
        super(product);
    }

    @Override
    public Double getPrice(){
        return product.getPrice() + 50;
    }

    @Override
    public String getName(){
        return product.getName() + " Customized";
    }
}
