package DesignPatterns.Decorator.Example;

// Essa é uma subclasse de ProductDecorator, 
// ela é usada como invólucro para 
// as classes que implementam a interface ProductProtocol, 
// nesse exemplo, o unico componente concreto
// são os objetos da classe TShirt, logo,
// essa subclasse irá personalizar esses objetos em tempo de execução,
// adicionando às camisas uma personalização, 
// o preço das camisas aumentarão em 50 e no nome da camisa será
// acrescido a palavra (Personalizado), 
// as camisas personalizadas também terão um novo atributo, cor personalizada

public class ProductCustomizedDecorator extends ProductDecorator {
    private String customizedColor; // As Camisetas personalizadas tem um novo atributo, cor personalizada

    public ProductCustomizedDecorator(ProductProtocol product, String customizedColor){
        super(product);
        this.customizedColor = customizedColor; // A cor personalizada escolhida será definida
    }

    @Override
    public Double getPrice(){
        return product.getPrice() + 50; // As Camisetas personalizadas tem um aumento de 50 Reais
    }

    @Override
    public String getName(){
        return product.getName() + " (Personalizado)"; // As Camisetas personalizadas tem um adicional no nome
    }

    public String getCustomizedColor(){
        return customizedColor; // As Camisetas personalizadas tem um novo atributo, cor personalizada
    }

    @Override
    public String toString(){
        return "Nome: " + getName() + "\n" +
                "Preço: " + getPrice() +
                "\n" + "Cor Personalizada: " + customizedColor;
    }
}
