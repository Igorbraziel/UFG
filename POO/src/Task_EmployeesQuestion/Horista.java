package Task_EmployeesQuestion;

public class Horista extends Funcionario {
    private Integer workedHours;
    private Double hourValue;

    public Horista(String name, String lastName, Integer workedHours, Double hourValue){
        super(name, lastName);
        this.workedHours = workedHours;
        this.hourValue = hourValue;
    }

    public void setWorkedHours(Integer workedHours){
        this.workedHours = workedHours;
    }

    public Integer getWorkedHours(){
        return this.workedHours;
    }

    public void setHourValue(Double hourValue){
        this.hourValue = hourValue;
    }

    public Double getHourValue(){
        return this.hourValue;
    }

    @Override
    public Double monthlyEarnings(){
        return this.workedHours * this.hourValue;
    }

    @Override
    public String toString(){
        return super.toString() +
        "Horas trabalhadas: " + workedHours + "\n" +
        "Valor da hora: " + hourValue + "\n";
    }
}
