package Task_DesignPattern_Observer;

public interface Revista {
    public void addSubscriber(Assinante subscriber);
    public void deleteSubscriber(Assinante subscriber);
    public int countSubscribers();
    public void notifySubscribers(Object obj);
}
