package Task_UML_Model;

public class Exemplar {
    private String nome;
    private int edicao;
    private Status status;

    public Exemplar(String nome, int edicao) {
        this.nome = nome;
        this.edicao = edicao;
        this.status = Status.DISPONIVEL;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getEdicao() {
        return edicao;
    }

    public void setEdicao(int edicao) {
        this.edicao = edicao;
    }

    public Status getStatus() {
        return status;
    }

    public void setStatus(Status status) {
        this.status = status;
    }
    
}
