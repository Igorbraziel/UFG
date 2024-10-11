package Task_AbstractionPOO;

public class Curso {
    private String nomeDoCurso;
    private int quantidadeSemestres;
    public int quantidadeAlunos;
    public int quantidadeProfessores;
    
    public Curso(String nomeDoCurso, int quantidadeSemestres, int quantidadeAlunos, int quantidadeProfessores){
        this.nomeDoCurso = nomeDoCurso;
        this.quantidadeSemestres = quantidadeSemestres;
        this.quantidadeAlunos = quantidadeAlunos;
        this.quantidadeProfessores = quantidadeProfessores;
    }

    public String toString(){
        return "Nome do Curso: " + nomeDoCurso + "\n" +
        "Quantidade de Semestres: " + quantidadeSemestres + "\n" +
        "Quatidade de Alunos: " + quantidadeAlunos + "\n" +
        "Quantidade de Professores: " + quantidadeProfessores;
    }
}