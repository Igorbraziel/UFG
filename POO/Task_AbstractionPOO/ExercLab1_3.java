import java.util.Locale;
import java.util.Scanner;

public class ExercLab1_3 {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);
        int N;
        String nome;
        int qtdAlunos, qtdSemestres, qtdProf;

        System.out.print("Quantidade de Cursos que serão inseridos: ");
        N = sc.nextInt();

        Curso[] vect = new Curso[N];

        for(int i = 0; i < N; i++){
            System.out.printf("Nome do curso %d: ", i + 1);
            sc.nextLine();
            nome = sc.nextLine();

            System.out.print("Quantidade de Semestres: ");
            qtdSemestres = sc.nextInt();

            System.out.print("Quantidade de Alunos: ");
            qtdAlunos = sc.nextInt();

            System.out.print("Quantidade de Professores: ");
            qtdProf = sc.nextInt();

            vect[i] = new Curso(nome, qtdSemestres, qtdAlunos, qtdProf);

            System.out.println("----------------------");
        }

        for(int i = 0; i < N; i++){
            System.out.printf("Curso %d:\n", i + 1);
            System.out.println(vect[i]);
            System.out.println("----------------------");
        }

        sc.close();
    }
}
