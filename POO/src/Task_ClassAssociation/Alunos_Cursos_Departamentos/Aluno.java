package Task_ClassAssociation.Alunos_Cursos_Departamentos;

public class Aluno {
    public String name;
    public int registration;
    public int year;
    public Curso course;

    public Aluno(String name, int registration, int year, Curso course){
        this.name = name;
        this.registration = registration;
        this.year = year;
        this.course = course;
    }

    public String showCourse(){
        return "Nome do Curso: " + course.name + "\n"
        + "Nome da Sigla do Curso: " + course.acronym + "\n";
    }

    public String toString(){
        return "Nome do Aluno: " + this.name + "\n"
        + "Matricula: " + this.registration + "\n"
        + "Ano: " + this.year + "{ \n"
        + this.showCourse() + "} \n";
    }
}
