package Task_DesignPattern_Observer;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args){
        List<Assinante> subscribersList = new ArrayList<>();
        Revista magazine = new RevistaVeja("Magazine Name", 123);

        subscribersList.add(new AssinanteAnual());
        subscribersList.add(new AssinanteMensal());
        subscribersList.add(new AssinanteMensal());
        subscribersList.add(new AssinanteAnual());

        for(Assinante subscriber : subscribersList){
            magazine.addSubscriber(subscriber);
        }

        ((RevistaVeja) magazine).setMagazineName("New Magazine Name");
        ((RevistaVeja) magazine).setEdition(77);
    }
}
