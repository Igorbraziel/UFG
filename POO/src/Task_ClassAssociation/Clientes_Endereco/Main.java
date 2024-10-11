package Task_ClassAssociation.Clientes_Endereco;

public class Main {
    public static void main(String[] args) {
        Endereco address1 = new Endereco("Rua Goiás", 222, "Vila 31", "Muro Preto", "Nova Veneza", "Goiás");
        Cliente customer1 = new Cliente("Nome do Cliente 1", "000.111.222-77", address1);

        Endereco address2 = new Endereco("Rua São Paulo", 301, "Paulista", "Muro Preto", "Ubatuba", "São Paulo");
        Cliente customer2 = new Cliente("Nome do Cliente 2", "444.555.222-88", address2);

        Endereco address3 = new Endereco("Rua Minas", 199, "Colombo", "Muro Azul", "Uberlândia", "Minas Gerais");
        Cliente customer3 = new Cliente("Nome do Cliente 3", "123.456.777-98", address3);

        System.out.println(customer1);
        System.out.println("----------------------");
        System.out.println(customer2);
        System.out.println("----------------------");
        System.out.println(customer3);
    }
}
