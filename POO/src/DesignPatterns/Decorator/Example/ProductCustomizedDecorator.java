package DesignPatterns.Decorator.Example;

public class ProductCustomizedDecorator extends ProductDecorator {
    private String customizedColor;

    public ProductCustomizedDecorator(ProductProtocol product, String customizedColor){
        super(product);
        this.customizedColor = customizedColor;
    }

    @Override
    public Double getPrice(){
        return product.getPrice() + 50;
    }

    @Override
    public String getName(){
        return product.getName() + " (Personalizado)";
    }

    public String getCustomizedColor(){
        return customizedColor;
    }

    @Override
    public String toString(){
        return "Nome: " + getName() + "\n" +
                "Preço: " + getPrice() +
                "\n" + "Cor Personalizada: " + customizedColor;
    }
}
