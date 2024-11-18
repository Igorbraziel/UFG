package DesignPatterns.Decorator.Example;

public class Main {
    public static void main(String[] args){
        TShirt tShirt = new TShirt(22.22, "new t-shirt");

        ProductStampDecorator tShirtWithStamp = new ProductStampDecorator(tShirt);
        ProductStampDecorator tShirtStampFrontAndBack = new ProductStampDecorator(tShirtWithStamp);

        ProductCustomizedDecorator customizedTShirt = new ProductCustomizedDecorator(tShirt);
        ProductCustomizedDecorator customizedAndStampedTShirt = new ProductCustomizedDecorator(tShirtWithStamp);

        System.out.println(tShirt.getPrice() + tShirt.getName());
        System.out.println(tShirtWithStamp.getPrice() + tShirtWithStamp.getName());
        System.out.println(tShirtStampFrontAndBack.getPrice() + tShirtStampFrontAndBack.getName());

        System.out.println(customizedTShirt.getPrice() + customizedTShirt.getName());
        System.out.println(customizedAndStampedTShirt.getPrice() + customizedAndStampedTShirt.getName());


    }
}
