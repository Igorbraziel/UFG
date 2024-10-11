package Task_EmployeesQuestion;

public class Administrador extends Funcionario{
    private Double monthlySalary; 

    public Administrador(String name, String lastName, Double monthlySalary){
        super(name, lastName);
        this.monthlySalary = monthlySalary;
    }

    public void setMonthlySalary(Double monthlySalary){
        this.monthlySalary = monthlySalary;
    }

    public Double getMonthlySalary(){
        return this.monthlySalary;
    }

    @Override
    public Double monthlyEarnings(){
        return this.monthlySalary;
    }

    @Override
    public String toString(){
        return super.toString() +
        "Salario mensal: " + monthlySalary + "\n";
    }
}