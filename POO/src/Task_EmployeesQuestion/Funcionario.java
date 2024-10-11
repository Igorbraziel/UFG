package Task_EmployeesQuestion;

public abstract class Funcionario {
    private String name;
    private String lastName;

    public Funcionario(String name, String lastName){
        this.name = name;
        this.lastName = lastName;
    }

    public void setName(String name){
        this.name = name;
    }

    public String getName(){
        return this.name;
    }

    public void setLastName(String lastName){
        this.lastName = lastName;
    }

    public String getLastName(){
        return this.lastName;
    }

    public abstract Double monthlyEarnings();

    public String toString(){
        return "Nome: " + name + "\n"
        + "Sobrenome: " + lastName + "\n";
    }
}
