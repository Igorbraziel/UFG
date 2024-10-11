package Comparison_PExPOO.Part3_Task;

import java.text.DecimalFormat;
import javax.swing.JOptionPane;

public class ProgramaPrincipal {
    public static void main(String[] args) {
        /* Criando 4 objetos da classe Aluno */
        Aluno aluno1 = new Aluno("Paulo",111,8.0,6.0,5.0);
        Aluno aluno2 = new Aluno("Maria",222,4.0,6.0,3.0);
        Aluno aluno3 = new Aluno("José",333,6.0,4.0,9.0);
        Aluno aluno4 = new Aluno("Patrícia",444,7.0,8.0,9.0);

        DecimalFormat df = new DecimalFormat("#.00");

        if(aluno1.calculaMedia() >= 7.0){
            JOptionPane.showMessageDialog(null, "Média do Aluno " + aluno1 + " = " +
            df.format(aluno1.calculaMedia()) + "\n-- ALUNO FOI APROVADO, MÉDIA FINAL >= 7.0");
        } else {
            JOptionPane.showMessageDialog(null, "Média do Aluno " + aluno1 + " = " +
            df.format(aluno1.calculaMedia()) + "\n-- ALUNO FOI REPROVADO, MÉDIA FINAL < 7.0");
        }

        if(aluno2.calculaMedia() >= 7.0){
            JOptionPane.showMessageDialog(null, "Média do Aluno " + aluno2 + " = " +
            df.format(aluno2.calculaMedia()) + "\n-- ALUNO FOI APROVADO, MÉDIA FINAL >= 7.0");
        } else {
            JOptionPane.showMessageDialog(null, "Média do Aluno " + aluno2 + " = " +
            df.format(aluno2.calculaMedia()) + "\n-- ALUNO FOI REPROVADO, MÉDIA FINAL < 7.0");
        }

        if(aluno3.calculaMedia() >= 7.0){
            JOptionPane.showMessageDialog(null, "Média do Aluno " + aluno3 + " = " +
            df.format(aluno3.calculaMedia()) + "\n-- ALUNO FOI APROVADO, MÉDIA FINAL >= 7.0");
        } else {
            JOptionPane.showMessageDialog(null, "Média do Aluno " + aluno3 + " = " +
            df.format(aluno3.calculaMedia()) + "\n-- ALUNO FOI REPROVADO, MÉDIA FINAL < 7.0");
        }

        if(aluno4.calculaMedia() >= 7.0){
            JOptionPane.showMessageDialog(null, "Média do Aluno " + aluno4 + " = " +
            df.format(aluno4.calculaMedia()) + "\n-- ALUNO FOI APROVADO, MÉDIA FINAL >= 7.0");
        } else {
            JOptionPane.showMessageDialog(null, "Média do Aluno " + aluno4 + " = " +
            df.format(aluno4.calculaMedia()) + "\n-- ALUNO FOI REPROVADO, MÉDIA FINAL < 7.0");
        }

        JOptionPane.showMessageDialog(null,"Média Geral = " +
        df.format((aluno1.calculaMedia() + aluno2.calculaMedia() +
        aluno3.calculaMedia() + aluno4.calculaMedia())/4 ));
    }
}
