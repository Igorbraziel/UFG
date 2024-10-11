package Task_ClassAssociation.Empregado_Empresa;

import Task_ClassAssociation.Clientes_Endereco.Endereco;
import java.util.List;
import java.util.ArrayList;

public class Empresa {
   public String cnpj;
   public String razao;
   public Endereco address;
   public List<Empregado> employeesList = new ArrayList<>();

   public Empresa(String cnpj, String razao, Endereco address){
        this.cnpj = cnpj;
        this.razao = razao;
        this.address = address;
   }

   public void addEmployee(Empregado employee){
        employeesList.add(employee);
   }

   public String showEmployees(){
    String employeesStr = "";
    for(Empregado employee : this.employeesList){
        employeesStr += "Nome do Empregado: " + employee.name + "\n"
        + "Matrícula do Empregado: " + employee.registration + "\n";
    }
    return employeesStr;
   }

   public String toString(){
        return "CNPJ da Empresa: " + this.cnpj + "\n"
        + "Razão da Empresa: " + this.razao + "\n"
        + "Endereço da Empresa:{\n" + this.address.toString() + "}\n"
        + "Empregados da Empresa:{\n" + this.showEmployees() + "}\n";
   }
}
