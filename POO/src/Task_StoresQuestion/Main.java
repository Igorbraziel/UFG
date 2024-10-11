package Task_StoresQuestion;

import java.util.List;
import java.util.ArrayList;
import Task_EmployeesQuestion.Gerente;

public class Main {
    public static void main(String[] args) {
        List<Loja> storesList = new ArrayList<>();
        
        storesList.add(new LojaConcreta(10, "11.222.333/0001-23", "Loja Concreta 1", "Rua Goias", new Gerente("Lucas", "Ribeiro", 1500.00, 1000.00)));
        storesList.add(new LojaConcreta(15, "12.232.343/0001-93", "Loja Concreta 2", "Rua Minas", new Gerente("Gabriel", "Junior", 2500.00, 12000.00)));
        storesList.add(new LojaConcreta(19, "31.888.355/0001-73", "Loja Concreta 3", "Rua Sao Paulo", new Gerente("Vitor", "Essado", 4500.00, 14000.00)));

        for(Loja store : storesList){
            System.out.print(store.storeData());
            System.out.println("--------------------------------------------------");
            ((LojaConcreta)store).registra_abertura_dia();
        }

        System.out.println();

        for(Loja store : storesList){
            System.out.print(store.storeData());
            System.out.println("--------------------------------------------------");
            ((LojaConcreta)store).registra_fechamento_dia();
        }

        System.out.println();

        for(Loja store : storesList){
            System.out.print(store.storeData());
            System.out.println("--------------------------------------------------");
        }
    }
}
