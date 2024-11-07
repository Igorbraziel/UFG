package DesignPatterns.Exercise2;

import java.util.List;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args){
        List<Assinante<?>> subscribersList = new ArrayList<>();
        Revista magazine = new RevistaVeja("Magazine Name", 123);
        subscribersList.add(new AssinanteAnual());
        subscribersList.add(new AssinanteMensal());
        subscribersList.add(new AssinanteMensal());
        for(Assinante<?> subscriber : subscribersList){
            magazine.addSubscriber(subscriber);
        }

        ((RevistaVeja) magazine).setMagazineName("New Magazine Name");
        ((RevistaVeja) magazine).setEdition(77);
    }
}
