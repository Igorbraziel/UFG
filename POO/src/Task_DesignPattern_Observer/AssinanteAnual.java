package Task_DesignPattern_Observer;

public class AssinanteAnual implements Assinante {
    @Override
    public void update(Object object){
        if(object instanceof Integer){
            System.out.println("The magazine edition has been changed, new edition: " + (Integer) object);
            System.out.println("------------------------------------------------------------------------");
        } else if (object instanceof String){
            System.out.println("The magazine name has been changed, new name: " + (String) object);
            System.out.println("------------------------------------------------------------------------");
        }
    }
}
