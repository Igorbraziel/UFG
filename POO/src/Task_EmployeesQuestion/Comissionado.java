package Task_EmployeesQuestion;

public class Comissionado extends Administrador {
    private Integer totalSales;
    private Double commissionPercentage;

    public Comissionado(String name, String lastName, Double monthlySalary, Integer totalSales, Double commissionPercentage){
        super(name, lastName, monthlySalary);
        this.totalSales = totalSales;
        this.commissionPercentage = commissionPercentage;
    }

    public void setTotalSales(Integer totalSales){
        this.totalSales = totalSales;
    }

    public Integer getTotalSales(){
        return this.totalSales;
    }

    public void setCommissionPercentage(Double commissionPercentage){
        this.commissionPercentage = commissionPercentage;
    }

    public Double getCommissionPercentage(){
        return this.commissionPercentage;
    }

    @Override
    public Double monthlyEarnings(){
        return super.getMonthlySalary() + (super.getMonthlySalary() * commissionPercentage * totalSales);
    }

    @Override
    public String toString(){
        return super.toString() +
        "Total de vendas: " + totalSales + "\n" +
        "Percentual de comissao: " + commissionPercentage + "\n";
    }

}
