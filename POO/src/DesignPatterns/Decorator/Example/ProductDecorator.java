package DesignPatterns.Decorator.Example;

// Essa é uma classe abstrata que implementa ProductProtocol, 
// ela servirá de base para as suas subclasses,
// que serão os Decorators concretos

// essa classe possui um atributo product,
// que será uma instância da classe ProductProtocol
// ou seja, será o objeto envolvido pelos Decorators

public abstract class ProductDecorator implements ProductProtocol {
    public ProductProtocol product;

    public ProductDecorator(ProductProtocol product){
        this.product = product;
    }

    public Double getPrice(){
        return product.getPrice(); // implementa o método getPrice() e delega todo o trabalho para o objeto envolvido
    }

    public String getName(){
        return product.getName(); // implementa o método getName() e delega todo o trabalho para o objeto envolvido
    }
}
