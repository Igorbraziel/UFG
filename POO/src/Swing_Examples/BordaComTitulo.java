package Swing_Examples;

import javax.swing.*;
import javax.swing.border.TitledBorder;
import java.awt.*;

public class BordaComTitulo {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Exemplo de Borda com Título");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 200);
        frame.setLayout(new BorderLayout());

        JPanel panel = new JPanel();
        panel.setBackground(Color.WHITE);

        // Adicionando uma borda com título
        TitledBorder bordaComTitulo = BorderFactory.createTitledBorder("Título da Borda");
        bordaComTitulo.setTitleColor(Color.BLUE); // Cor do título
        panel.setBorder(bordaComTitulo);

        frame.add(panel, BorderLayout.CENTER);

        frame.setVisible(true);
    }
}

