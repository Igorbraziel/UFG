package Task_UML_Model;

public class Livro extends Exemplar {
    private String nomeDoAutor;

    public Livro(String nome, int edicao, String nomeDoAutor) {
        super(nome, edicao);
        this.nomeDoAutor = nomeDoAutor;
    }

    public String getNomeDoAutor() {
        return nomeDoAutor;
    }

    public void setNomeDoAutor(String nomeDoAutor) {
        this.nomeDoAutor = nomeDoAutor;
    }

}
