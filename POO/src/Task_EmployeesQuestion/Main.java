package Task_EmployeesQuestion;

import java.util.List;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args){
        List<Funcionario> employeesList = new ArrayList<>();

        employeesList.add(new Horista("Horista 1", "Sobrenome do Horista 1", 10, 50.0));
        employeesList.add(new Horista("Horista 2", "Sobrenome do Horista 2", 20, 100.0));
        
        employeesList.add(new Administrador("Admin 1", "Sobrenome do Admin 1", 2000.00));
        employeesList.add(new Administrador("Admin 2", "Sobrenome do Admin 2", 2400.00));
        employeesList.add(new Administrador("Admin 3", "Sobrenome do Admin 3", 2800.00));
        employeesList.add(new Administrador("Admin 4", "Sobrenome do Admin 4", 3200.00));

        employeesList.add(new Comissionado("Comissionado 1", "Sobrenome do Comissionado 1", 4000.00, 10, 0.01));
        employeesList.add(new Comissionado("Comissionado 2", "Sobrenome do Comissionado 2", 4500.00, 12, 0.02));
        employeesList.add(new Comissionado("Comissionado 3", "Sobrenome do Comissionado 3", 5000.00, 14, 0.03));
        
        employeesList.add(new Gerente("Gerente 1", "Sobrenome do Gerente 1", 6500.00, 400.50));

        for(Funcionario employee : employeesList){
            System.out.print(employee);
            System.out.println("Ganho mensal do funcionario: " + employee.monthlyEarnings());
            System.out.println("---------------------------------------------------");
        }
    }
}
