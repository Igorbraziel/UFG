package DesignPatterns.Singleton.Example;

public final class Bank {
    private static Bank instance;
    private Integer code;
    private String name;

    private Bank(){
        this.code = 1;
        this.name = "Bank of Brazil";
    }

    public static Bank getInstance(){
        if(instance == null){
            instance = new Bank();
        }
        return instance;
    }

    public Integer getCode(){
        return code;
    }

    public String getName(){
        return name;
    }
}
