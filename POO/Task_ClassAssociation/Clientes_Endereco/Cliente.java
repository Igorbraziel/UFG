package Clientes_Endereco;

public class Cliente {
    public String name;
    public String cpf;
    public Endereco address;

    public Cliente(String name, String cpf, Endereco address){
        this.name = name;
        this.cpf = cpf;
        this.address = address;
    }

    public String toString(){
        return "Nome do Cliente: " + this.name + "\n"
        + "CPF do Cliente: " + this.cpf + "\n"
        + "Endereço do Cliente: {\n" + this.address.toString() + "}";
    }
}
