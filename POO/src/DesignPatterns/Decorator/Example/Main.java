package DesignPatterns.Decorator.Example;

public class Main {
    public static void main(String[] args){
        TShirt camiseta = new TShirt(72.99, "Camiseta Nike");

        ProductStampDecorator camisetaEstampada = new ProductStampDecorator(camiseta);
        ProductStampDecorator camisetaEstampadaAtras = new ProductStampDecorator(camisetaEstampada);

        ProductCustomizedDecorator camisetaPersonalizada = new ProductCustomizedDecorator(camiseta, "Azul");
        ProductCustomizedDecorator camisetaEstampadaPersonalizada = new ProductCustomizedDecorator(camisetaEstampada, "Verde");

        System.out.println(camiseta);

        System.out.println(camisetaEstampada);

        System.out.println(camisetaEstampadaAtras);

        System.out.println(camisetaPersonalizada);

        System.out.println(camisetaEstampadaPersonalizada);
    }
}
