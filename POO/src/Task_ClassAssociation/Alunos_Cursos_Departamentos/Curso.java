package Task_ClassAssociation.Alunos_Cursos_Departamentos;

import java.util.List;
import java.util.ArrayList;

public class Curso { 
    public String name;
    public String acronym;
    public Departamento department;
    public List<Aluno> studentsList = new ArrayList<>();

    public Curso(String name, String acronym, Departamento department){
        this.name = name;
        this.acronym = acronym;
        this.department = department;
    }

    public void addStudent(Aluno student){
            this.studentsList.add(student);
    }

    public String showDepartment(){
        return "Nome do Departamento: " + this.department.name + "\n"
        + "Sigla do Departamento: " + this.department.acronym + "\n";
    }

    public String showStudents(){
        String studentsStr = "";
        for(Aluno student : studentsList){
            studentsStr += "Nome do Aluno: " + student.name + "\n"
            + "Matricula: " + student.registration + "\n"
            + "Ano: " + student.year + "\n";
        }
        return studentsStr;
    }

    public String toString(){
        return "Nome do Curso: " + this.name + "\n"
        + "Sigla do Curso: " + this.acronym + "\n"
        + "Alunos do Curso: {\n" 
        + this.showStudents() + "}\n"
        + "Departamento: {\n" 
        + this.showDepartment() + "}\n";
    }
}
