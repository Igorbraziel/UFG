package DesignPatterns.Exercise2;

import java.util.List;
import java.util.ArrayList;

public class RevistaVeja implements Revista {
    private List<Assinante> subscribersList = new ArrayList<>();
    private String magazineName;
    private Integer edition;

    public RevistaVeja(String magazineName, Integer edition){
        this.magazineName = magazineName;
        this.edition = edition;
    }

    public String getMagazineName(){
        return magazineName;
    }

    public void setMagazineName(String magazineName){
        this.magazineName = magazineName;
        notifySubscribers(magazineName);
    }

    public Integer getEdition(){
        return edition;
    }

    public void setEdition(Integer edition){
        this.edition = edition;
        notifySubscribers(edition);
    }

    @Override
    public void addSubscriber(Assinante subscriber){
        subscribersList.add(subscriber);
    }

    @Override
    public void deleteSubscriber(Assinante subscriber){
        subscribersList.remove(subscriber);
    }

    @Override
    public int countSubscribers(){
        return subscribersList.size();
    }

    @Override
    public void notifySubscribers(Object obj){
        for(Assinante subscriber : subscribersList){
            subscriber.update(obj);
        }
    }
}
