package Part3_Task;

import java.text.DecimalFormat;
import javax.swing.JOptionPane;

public class ProgramaCalculaMedia {
    public static void main(String[] args) {
        String nomeAluno1 = "Paulo";
        int matAluno1 = 111;
        double nota1Aluno1 = 8.0;
        double nota2Aluno1 = 6.0;
        double nota3Aluno1 = 5.0;

        String nomeAluno2 = "Maria";
        int matAluno2 = 222;
        double nota1Aluno2 = 4.0;
        double nota2Aluno2 = 6.0;
        double nota3Aluno2 = 3.0;

        String nomeAluno3 = "José";
        int matAluno3 = 333;
        double nota1Aluno3 = 6.0;
        double nota2Aluno3 = 4.0;
        double nota3Aluno3 = 9.0;

        String nomeAluno4 = "Patrícia";
        int matAluno4 = 444;
        double nota1Aluno4 = 7.0;
        double nota2Aluno4 = 8.0;
        double nota3Aluno4 = 9.0;

        double mediaAluno1 = (nota1Aluno1 + nota2Aluno1 + nota3Aluno1)/3;
        double mediaAluno2 = (nota1Aluno2 + nota2Aluno2 + nota3Aluno2)/3;
        double mediaAluno3 = (nota1Aluno3 + nota2Aluno3 + nota3Aluno3)/3;
        double mediaAluno4 = (nota1Aluno4 + nota2Aluno4 + nota3Aluno4)/3;

        double mediaGeral = (mediaAluno1 + mediaAluno2 + mediaAluno3 + mediaAluno4)/4;

        DecimalFormat df = new DecimalFormat("#.00");

        if(mediaAluno1 >= 7.0){
            JOptionPane.showMessageDialog(null,"Média do(a) Aluno(a) " + nomeAluno1 + 
            "(Matrícula - " + matAluno1 + ") = " + df.format(mediaAluno1) + "\n-- ALUNO FOI APROVADO, MÉDIA FINAL >= 7.0");
        } else {
            JOptionPane.showMessageDialog(null,"Média do(a) Aluno(a) " + nomeAluno1 + 
            "(Matrícula - " + matAluno1 + ") = " + df.format(mediaAluno1) + "\n-- ALUNO FOI REPROVADO, MÉDIA FINAL < 7.0");
        }

        if(mediaAluno2 >= 7.0){
            JOptionPane.showMessageDialog(null,"Média do(a) Aluno(a) " + nomeAluno2 + 
            "(Matrícula - " + matAluno2 + ") = " + df.format(mediaAluno2) + "\n-- ALUNO FOI APROVADO, MÉDIA FINAL >= 7.0");
        } else {
            JOptionPane.showMessageDialog(null,"Média do(a) Aluno(a) " + nomeAluno2 + 
            "(Matrícula - " + matAluno2 + ") = " + df.format(mediaAluno2) + "\n-- ALUNO FOI REPROVADO, MÉDIA FINAL < 7.0");
        }

        if(mediaAluno3 >= 7.0){
            JOptionPane.showMessageDialog(null,"Média do(a) Aluno(a) " + nomeAluno3 + 
            "(Matrícula - " + matAluno3 + ") = " + df.format(mediaAluno3) + "\n-- ALUNO FOI APROVADO, MÉDIA FINAL >= 7.0");
        } else {
            JOptionPane.showMessageDialog(null,"Média do(a) Aluno(a) " + nomeAluno3 + 
            "(Matrícula - " + matAluno3 + ") = " + df.format(mediaAluno3) + "\n-- ALUNO FOI REPROVADO, MÉDIA FINAL < 7.0");
        }

        if(mediaAluno4 >= 7.0){
            JOptionPane.showMessageDialog(null,"Média do(a) Aluno(a) " + nomeAluno4 + 
            "(Matrícula - " + matAluno4 + ") = " + df.format(mediaAluno4) + "\n-- ALUNO FOI APROVADO, MÉDIA FINAL >= 7.0");
        } else {
            JOptionPane.showMessageDialog(null,"Média do(a) Aluno(a) " + nomeAluno4 + 
            "(Matrícula - " + matAluno4 + ") = " + df.format(mediaAluno4) + "\n-- ALUNO FOI REPROVADO, MÉDIA FINAL < 7.0");
        }

        JOptionPane.showMessageDialog(null,"Média Geral = " + df.format(mediaGeral));
    }
}
