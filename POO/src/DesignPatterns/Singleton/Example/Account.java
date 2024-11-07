package DesignPatterns.Singleton.Example;

public class Account {
    private Bank bank;
    private Integer code;
    private String name;

    public Account(Integer code, String name){
        this.bank = Bank.getInstance();
        this.code = code;
        this.name = name;
    }

    public Bank getBank() {
        return bank;
    }

    public void setBank(Bank bank) {
        this.bank = bank;
    }

    public Integer getCode() {
        return code;
    }

    public void setCode(Integer code) {
        this.code = code;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
