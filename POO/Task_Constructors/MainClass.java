package Task_Constructors;

import java.util.Scanner;

public class MainClass {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int code, quantity;
        String name, productType;
        double value;

        System.out.println("Produto 1");
        System.out.print("Informe o código: ");
        code = sc.nextInt();
        Produto p1 = new Produto(code);
        p1.inserir("Jogo Batalha Naval", 50, "Jogo", 400.50);
        p1.vender(30);
        p1.comprar(30);
        p1.comprar(60, 300);
        System.out.println(p1.toString());

        System.out.println("Produto 2");
        System.out.print("Informe o código: ");
        code = sc.nextInt();
        System.out.print("Informe o nome: ");
        sc.nextLine();
        name = sc.nextLine();
        Produto p2 = new Produto(code, name);
        p2.vender(20);
        p2.comprar(10);
        p2.comprar(80, 700);
        System.out.println(p2.toString());

        System.out.println("Produto 3");
        System.out.print("Informe o código: ");
        code = sc.nextInt();
        System.out.print("Informe o nome: ");
        sc.nextLine();
        name = sc.nextLine();
        System.out.print("Informe a quantidade: ");
        quantity = sc.nextInt();
        Produto p3 = new Produto(code, name, quantity);
        p3.vender(209);
        p3.comprar(1);
        p3.comprar(30, 875);
        System.out.println(p3.toString());

        System.out.println("Produto 4");
        System.out.print("Informe o código: ");
        code = sc.nextInt();
        System.out.print("Informe o nome: ");
        sc.nextLine();
        name = sc.nextLine();
        System.out.print("Informe a quantidade: ");
        quantity = sc.nextInt();
        System.out.print("Informe o tipo: ");
        sc.nextLine();
        productType = sc.nextLine();
        System.out.print("Informe o valor: ");
        value = sc.nextDouble();
        Produto p4 = new Produto(code, name, quantity, productType, value);
        p4.vender(2090);
        p4.comprar(1301);
        p4.comprar(3099, 50000);
        System.out.println(p4.toString());

        System.out.println("Comparação p1 com p2: São Iguais? " + p1.igual(p2));
        System.out.println("Comparação p1 com p3: São Iguais? " + p1.igual(p3));
        System.out.println("Comparação p1 com p4: São Iguais? " + p1.igual(p4));

        System.out.println("Comparação p2 com p1: São Iguais? " + p2.igual(p1));
        System.out.println("Comparação p2 com p3: São Iguais? " + p2.igual(p3));
        System.out.println("Comparação p2 com p4: São Iguais? " + p2.igual(p4));

        System.out.println("Comparação p3 com p1: São Iguais? " + p3.igual(p1));
        System.out.println("Comparação p3 com p2: São Iguais? " + p3.igual(p2));
        System.out.println("Comparação p3 com p4: São Iguais? " + p3.igual(p4));

        System.out.println("Comparação p4 com p1: São Iguais? " + p4.igual(p1));
        System.out.println("Comparação p4 com p2: São Iguais? " + p4.igual(p2));
        System.out.println("Comparação p4 com p3: São Iguais? " + p4.igual(p3));

        sc.close();
    }
}
