package Alunos_Cursos_Departamentos;

import java.util.List;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        List<Departamento> departmentList = new ArrayList<>();
        List<Curso> coursesList = new ArrayList<>();
        List<Aluno> studentsList = new ArrayList<>();

        Departamento d1 = new Departamento("Departamento 1", "Sigla do Departamento 1");
        Departamento d2 = new Departamento("Departamento 2", "Sigla do Departamento 2");

        Curso c1 = new Curso("Curso 1", "Sigla do Curso 1", d1);
        d1.addCourse(c1);
        Curso c2 = new Curso("Curso 2", "Sigla do Curso 2", d1);
        d1.addCourse(c2);
        Curso c3 = new Curso("Curso 3", "Sigla do Curso 3", d2);
        d2.addCourse(c3);
        Curso c4 = new Curso("Curso 4", "Sigla do Curso 4", d2);
        d2.addCourse(c4);

        Aluno a1 = new Aluno("Aluno 1", 10, 2020, c1);
        Aluno a2 = new Aluno("Aluno 2", 11, 2021, c1);
        c1.addStudent(a1);
        c1.addStudent(a2);
        Aluno a3 = new Aluno("Aluno 3", 12, 2022, c2);
        Aluno a4 = new Aluno("Aluno 4", 13, 2023, c2);
        c2.addStudent(a3);
        c2.addStudent(a4);
        Aluno a5 = new Aluno("Aluno 5", 14, 2024, c3);
        Aluno a6 = new Aluno("Aluno 6", 15, 2025, c3);
        c3.addStudent(a5);
        c3.addStudent(a6);
        Aluno a7 = new Aluno("Aluno 7", 16, 2026, c4);
        Aluno a8 = new Aluno("Aluno 8", 17, 2027, c4);
        c4.addStudent(a7);
        c4.addStudent(a8);

        departmentList.add(d1);
        departmentList.add(d2);

        coursesList.add(c1);
        coursesList.add(c2);
        coursesList.add(c3);
        coursesList.add(c4);

        studentsList.add(a1);
        studentsList.add(a2);
        studentsList.add(a3);
        studentsList.add(a4);
        studentsList.add(a5);
        studentsList.add(a6);
        studentsList.add(a7);
        studentsList.add(a8);

        // IREI EXIBIR OS CURSOS POIS ELES POSSUEM LIGAÇÃO COM ALUNOS E DEPARTAMENTOS DIRETAMENTE
        for(Curso course: coursesList){
            System.out.println("--------------------------------");
            System.out.println(course);
        }
    }
}
