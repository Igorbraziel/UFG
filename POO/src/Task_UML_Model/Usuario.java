package Task_UML_Model;

import java.util.List;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.stream.Collectors;

public class Usuario extends Pessoa {
    private List<Emprestimo> emprestimos = new ArrayList<>();
    private Biblioteca biblioteca;

    public Usuario(String nome, int idade, String genero){
        super(nome, idade, genero);
    }

    public List<Exemplar> consultarLivros(){
        return biblioteca.getListaExemplares().stream().filter(x -> x instanceof Livro).collect(Collectors.toList());
    }

    public void emprestar(Exemplar exemplar, LocalDate dataEmprestimo, LocalDate dataDevolucao){
        emprestimos.add(new Emprestimo(dataEmprestimo, dataDevolucao, this, exemplar));
    }

    public void renovar(Emprestimo emprestimo, LocalDate novaDataEmprestimo, LocalDate novaDataDevolucao){
        emprestimo.renovar(novaDataEmprestimo, novaDataDevolucao);
    }

    public void devolver(Emprestimo emprestimo){
        emprestimos.remove(emprestimo);
        emprestimo.getExemplar().setStatus(Status.DISPONIVEL);
        emprestimo = null;
    }

    public boolean reservar(Exemplar exemplar, LocalDate dataReservaInicio, LocalDate dataReservaFim){
        if(exemplar.getStatus() == Status.DISPONIVEL){
            emprestimos.add(new Emprestimo(dataReservaInicio, dataReservaFim, this, exemplar, Status.RESERVADO));
            return true;
        } else if(exemplar.getStatus() == Status.EMPRESTADO){
            exemplar.setStatus(Status.EMPRESTADO_RESERVADO);
            return true;
        } 
        return false;
    }

    public List<Emprestimo> getEmprestimos() {
        return emprestimos;
    }

    public void setEmprestimos(List<Emprestimo> emprestimos) {
        this.emprestimos = emprestimos;
    }

    public Biblioteca getBiblioteca() {
        return biblioteca;
    }

    public void setBiblioteca(Biblioteca biblioteca) {
        this.biblioteca = biblioteca;
    }

}
