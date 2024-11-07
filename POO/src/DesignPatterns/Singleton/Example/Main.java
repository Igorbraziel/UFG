package DesignPatterns.Singleton.Example;

import java.util.Locale;

public class Main {
    public static void main(String[] args){
        Locale.setDefault(Locale.US);
        Bank myBank = Bank.getInstance();
        Account myAccount = new Account(22, "Igor");
        System.out.println(myBank.equals(myAccount.getBank()));
        System.out.println(myBank == myAccount.getBank());
    }
}
