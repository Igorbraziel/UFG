package Task_UML_Model;

import java.util.List;
import java.util.stream.Collectors;

public class Bibliotecario extends Pessoa {
    private Biblioteca biblioteca;

    public Bibliotecario(String nome, int idade, String genero, Biblioteca biblioteca){
        super(nome, idade, genero);
        this.biblioteca = biblioteca;
    }

    public boolean cadastrar(Exemplar exemplar){
        if(ServicoValidacao.validar(exemplar)){
            biblioteca.addExemplar(exemplar);
            return true;
        } 
        return false;
    }

    public List<Exemplar> consultarLivros(){
        return biblioteca.getListaExemplares().stream().filter(x -> x instanceof Livro).collect(Collectors.toList());
    }

    public Biblioteca getBiblioteca() {
        return biblioteca;
    }

    public void setBiblioteca(Biblioteca biblioteca) {
        this.biblioteca = biblioteca;
    }

}
