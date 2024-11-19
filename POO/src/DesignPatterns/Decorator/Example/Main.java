package DesignPatterns.Decorator.Example;

public class Main {
    public static void printLine(){
        System.out.println("------------------------------------------------");
    }

    public static void main(String[] args){
        TShirt camiseta = new TShirt(72.99, "Camiseta Nike");

        ProductStampDecorator camisetaEstampada = new ProductStampDecorator(camiseta);
        ProductStampDecorator camisetaEstampadaAtras = new ProductStampDecorator(camisetaEstampada);

        ProductCustomizedDecorator camisetaPersonalizada = new ProductCustomizedDecorator(camiseta, "Azul");
        ProductCustomizedDecorator camisetaEstampadaPersonalizada = new ProductCustomizedDecorator(camisetaEstampada, "Verde");

        System.out.println(camiseta);
        printLine();

        System.out.println(camisetaEstampada);
        printLine();

        System.out.println(camisetaEstampadaAtras);
        printLine();

        System.out.println(camisetaPersonalizada);
        printLine();

        System.out.println(camisetaEstampadaPersonalizada);
    }
}
