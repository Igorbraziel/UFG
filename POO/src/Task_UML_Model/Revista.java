package Task_UML_Model;

public class Revista extends Exemplar {
    private String marcaDaRevista;

    public Revista(String nome, int edicao, String marcaDaRevista) {
        super(nome, edicao);
        this.marcaDaRevista = marcaDaRevista;
    }

    public String getMagazineBrand() {
        return marcaDaRevista;
    }

    public void setMagazineBrand(String marcaDaRevista) {
        this.marcaDaRevista = marcaDaRevista;
    } 
}
