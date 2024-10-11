package Task_StoresQuestion;

public abstract class Loja {
    public Integer id;
    public String cnpj;
    public String companyName;
    public Boolean openStatus;

    public Loja(Integer id, String cnpj, String companyName){
        this.id = id;
        this.cnpj = cnpj;
        this.companyName = companyName;
        this.openStatus = false;
    }

    public String storeData(){
        return "Razao social: " + companyName + "\n"
        + "Cnpj: " + cnpj + "\n" 
        + "Status: " + openStatus + "\n";
    }
}
