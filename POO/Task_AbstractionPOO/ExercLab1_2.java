import java.util.Locale;
import java.util.Scanner;

public class ExercLab1_2 {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);
        Curso curso1, curso2, curso3, curso4;
        String nome;
        int qtdAlunos, qtdSemestres, qtdProf;

        System.out.print("Nome do curso: ");
        nome = sc.nextLine();

        System.out.print("Quantidade de Semestres: ");
        qtdSemestres = sc.nextInt();

        System.out.print("Quantidade de Alunos: ");
        qtdAlunos = sc.nextInt();

        System.out.print("Quantidade de Professores: ");
        qtdProf = sc.nextInt();

        curso1 = new Curso(nome, qtdSemestres, qtdAlunos, qtdProf);
        
        System.out.println("----------------------");
        System.out.print("Nome do curso: ");
        sc.nextLine();
        nome = sc.nextLine();

        System.out.print("Quantidade de Semestres: ");
        qtdSemestres = sc.nextInt();

        System.out.print("Quantidade de Alunos: ");
        qtdAlunos = sc.nextInt();

        System.out.print("Quantidade de Professores: ");
        qtdProf = sc.nextInt();

        curso2 = new Curso(nome, qtdSemestres, qtdAlunos, qtdProf);


        System.out.println("----------------------");
        System.out.print("Nome do curso: ");
        sc.nextLine();
        nome = sc.nextLine();

        System.out.print("Quantidade de Semestres: ");
        qtdSemestres = sc.nextInt();

        System.out.print("Quantidade de Alunos: ");
        qtdAlunos = sc.nextInt();

        System.out.print("Quantidade de Professores: ");
        qtdProf = sc.nextInt();

        curso3 = new Curso(nome, qtdSemestres, qtdAlunos, qtdProf);

        System.out.println("----------------------");
        System.out.print("Nome do curso: ");
        sc.nextLine();
        nome = sc.nextLine();

        System.out.print("Quantidade de Semestres: ");
        qtdSemestres = sc.nextInt();

        System.out.print("Quantidade de Alunos: ");
        qtdAlunos = sc.nextInt();

        System.out.print("Quantidade de Professores: ");
        qtdProf = sc.nextInt();

        curso4 = new Curso(nome, qtdSemestres, qtdAlunos, qtdProf);

        System.out.println("----------------------");
        System.out.println("Curso 1:");
        System.out.println(curso1);

        System.out.println("----------------------");
        System.out.println("Curso 2:");
        System.out.println(curso2);

        System.out.println("----------------------");
        System.out.println("Curso 3:");
        System.out.println(curso3);

        System.out.println("----------------------");
        System.out.println("Curso 4:");
        System.out.println(curso4);

        sc.close();
    }
}
