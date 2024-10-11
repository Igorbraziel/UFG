package Task_StoresQuestion;

import Task_EmployeesQuestion.Gerente;

public class LojaConcreta extends Loja implements Registro {
    public String address;
    public Gerente manager;
    
    public LojaConcreta(Integer id, String cnpj, String companyName, String address, Gerente manager){
        super(id, cnpj, companyName);
        this.address = address;
        this.manager = manager;
    }

    public void registra_abertura_dia(){
        if(this.openStatus == false){
            this.openStatus = true; 
        }
    }

    public void registra_fechamento_dia(){
        if(this.openStatus == true){
            this.openStatus = false;
        }
    }

    @Override
    public String storeData(){
        return "Identificador: " + id + '\n' +
        "CNPJ: " + cnpj + '\n' +
        "Razao Social: " + companyName + '\n' + 
        "Endereco: " + address + '\n' + 
        "STATUS DE ABERTURA: " + openStatus + "\n" +
        "Gerente: {\n" + manager + "}\n";
    }
}
