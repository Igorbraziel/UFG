package Task_ClassAssociation.Clientes_Endereco;

public class Endereco {
    public String street;
    public int number;
    public String neighborhood;
    public String complement;
    public String city;
    public String state;

    public Endereco(String street, int number, String neighborhood, String complement, String city, String state){
        this.street = street;
        this.number = number;
        this.neighborhood = neighborhood;
        this.complement = complement;
        this.city = city;
        this.state = state;
    }

    public String toString(){
        return "Rua: " + this.street + "\n"
        + "Número: " + this.number + "\n"
        + "Bairro: " + this.neighborhood + "\n"
        + "Complemento: " + this.complement + "\n"
        + "Cidade: " + this.city + "\n"
        + "Estado: " + this.state + "\n";
    }
}
