package Task_EmployeesQuestion;

public class Gerente extends Administrador {
    private Double bonus;

    public Gerente(String name, String lastName, Double monthlySalary, Double bonus){
        super(name, lastName, monthlySalary);
        this.bonus = bonus;
    }

    public void setBonus(Double bonus){
        this.bonus = bonus;
    }

    public Double getBonus(){
        return this.bonus;
    }

    @Override
    public Double monthlyEarnings(){
        return super.getMonthlySalary() + this.bonus;
    }

    @Override
    public String toString(){
        return super.toString() +
        "Bonificacao: " + bonus + "\n";
    }
}
