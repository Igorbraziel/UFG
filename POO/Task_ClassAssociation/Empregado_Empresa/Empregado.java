package Empregado_Empresa;

public class Empregado {
    public String name;
    public int registration;
    public Empresa company;

    public Empregado(String name, int registration, Empresa company){
        this.name = name;
        this.registration = registration;
        this.company = company;
    }

    public String showCompany(){
        return "CNPJ da Empresa: " + this.company.cnpj + "\n"
        + "Razão da Empresa: " + this.company.razao + "\n"
        + "Endereço da Empresa:{\n" + this.company.address.toString() + "}\n";
    }

    public String toString(){
        return "Nome do Empregado: " + this.name + "\n"
        + "Matrícula do Empregado: " + this.registration + "\n"
        + "Empresa do Empregado: {\n" + this.showCompany() + "}\n";
    }
}
