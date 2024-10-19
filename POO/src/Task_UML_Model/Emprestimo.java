package Task_UML_Model;

import java.time.LocalDate;

public class Emprestimo {
    private LocalDate dataEmprestimo;
    private LocalDate dataDevolucao;
    private Usuario usuario;
    private Exemplar exemplar;

    public Emprestimo(LocalDate dataEmprestimo, LocalDate dataDevolucao, Usuario usuario, Exemplar exemplar) {
        this.dataEmprestimo = dataEmprestimo;
        this.dataDevolucao = dataDevolucao;
        this.usuario = usuario;
        this.exemplar = exemplar;
        this.exemplar.setStatus(Status.EMPRESTADO);
    }

    public Emprestimo(LocalDate dataEmprestimo, LocalDate dataDevolucao, Usuario usuario, Exemplar exemplar,
        Status status) {
        this.dataEmprestimo = dataEmprestimo;
        this.dataDevolucao = dataDevolucao;
        this.usuario = usuario;
        this.exemplar = exemplar;
        this.exemplar.setStatus(status);
    }

    public void renovar(LocalDate novaDataEmprestimo, LocalDate novaDataDevolucao){
        this.dataEmprestimo = novaDataEmprestimo;
        this.dataDevolucao = novaDataDevolucao;
    }

    public LocalDate getDataEmprestimo() {
        return dataEmprestimo;
    }

    public void setDataEmprestimo(LocalDate dataEmprestimo) {
        this.dataEmprestimo = dataEmprestimo;
    }

    public LocalDate getDataDevolucao() {
        return dataDevolucao;
    }

    public void setDataDevolucao(LocalDate dataDevolucao) {
        this.dataDevolucao = dataDevolucao;
    }

    public Usuario getUsuario() {
        return usuario;
    }

    public void setUsuario(Usuario usuario) {
        this.usuario = usuario;
    }

    public Exemplar getExemplar() {
        return exemplar;
    }

    public void setExemplar(Exemplar exemplar) {
        this.exemplar = exemplar;
    }
    
}
