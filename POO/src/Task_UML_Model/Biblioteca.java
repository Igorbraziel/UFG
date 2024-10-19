package Task_UML_Model;

import java.util.List;
import java.util.ArrayList;

public class Biblioteca {
    private List<Exemplar> listaExemplares = new ArrayList<>();
    private List<Bibliotecario> listaBibliotecarios = new ArrayList<>();
    private List<Usuario> listaUsuarios = new ArrayList<>();

    public Biblioteca(){
        super();
    }

    public Biblioteca(List<Exemplar> listaExemplares, List<Bibliotecario> listaBibliotecarios,
            List<Usuario> listaUsuarios) {
        this.listaExemplares = listaExemplares;
        this.listaBibliotecarios = listaBibliotecarios;
        this.listaUsuarios = listaUsuarios;
    }

    public List<Exemplar> getListaExemplares() {
        return listaExemplares;
    }

    public void setListaExemplares(List<Exemplar> listaExemplares) {
        this.listaExemplares = listaExemplares;
    }

    public List<Bibliotecario> getListaBibliotecarios() {
        return listaBibliotecarios;
    }

    public void setListaBibliotecarios(List<Bibliotecario> listaBibliotecarios) {
        this.listaBibliotecarios = listaBibliotecarios;
    }

    public List<Usuario> getListaUsuarios() {
        return listaUsuarios;
    }

    public void setListaUsuarios(List<Usuario> listaUsuarios) {
        this.listaUsuarios = listaUsuarios;
    }

    public void addExemplar(Exemplar exemplar){
        listaExemplares.add(exemplar);
    }

    public void addUsuario(Usuario usuario){
        listaUsuarios.add(usuario);
    }

    public void addBibliotecario(Bibliotecario bibliotecario){
        listaBibliotecarios.add(bibliotecario);
    }
    
}
