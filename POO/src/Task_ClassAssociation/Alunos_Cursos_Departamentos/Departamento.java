package Task_ClassAssociation.Alunos_Cursos_Departamentos;

import java.util.List;
import java.util.ArrayList;

public class Departamento {
    public String name;
    public String acronym; 
    public List<Curso> coursesList = new ArrayList<>();

    public Departamento(String name, String acronym){
        this.name = name;
        this.acronym = acronym;
    }

    public void addCourse(Curso course){
        this.coursesList.add(course);
    }

    public String showCursos(){
        String coursesStr = "";
        for(Curso course : coursesList){
            coursesStr += "Nome do Curso: " + course.name + "\n"
            + "Nome da Sigla do Curso: " + course.acronym + "\n";
        }
        return coursesStr;
    }

    public String toString(){
        return "Nome do departamento: " + this.name + "\n"
        + "Sigla do departamento: " + this.acronym + "\n"
        + "Cursos do departamento: { \n"
        + this.showCursos() + "\n}";
    }
}
