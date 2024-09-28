package Empregado_Empresa;

import Clientes_Endereco.Endereco;

public class Main {
    public static void main(String[] args) {
        Endereco address = new Endereco("Rua Goiás", 222, "Vila 31", "Muro Preto", "Nova Veneza", "Goiás");
        Empresa company = new Empresa("451.112.234/0001-99", "Razão da Empresa", address);

        Empregado employee1 = new Empregado("Empregado 1", 101, company);
        Empregado employee2 = new Empregado("Empregado 2", 102, company);
        Empregado employee3 = new Empregado("Empregado 3", 103, company);
        Empregado employee4 = new Empregado("Empregado 4", 104, company);        

        company.addEmployee(employee1);
        company.addEmployee(employee2);
        company.addEmployee(employee3);
        company.addEmployee(employee4);

        System.out.println("---------------------------------------------");
        System.out.println(company);
        System.out.println("---------------------------------------------");
    }
}
