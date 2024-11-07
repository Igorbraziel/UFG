package DesignPatterns.Exercise2;

public class AssinanteAnual implements Assinante<Object> {
    @Override
    public void update(Object object){
        if(object instanceof Integer){
            System.out.println("The magazine edition has been changed, new edition: " + (Integer) object);
        } else if (object instanceof String){
            System.out.println("The magazine name has been changed, new name: " + (String) object);
        }
    }
}
