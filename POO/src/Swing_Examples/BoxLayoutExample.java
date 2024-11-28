package Swing_Examples;

import javax.swing.*;
import java.awt.*;

public class BoxLayoutExample {
    public static void main(String[] args) {
        JFrame frame = new JFrame("BoxLayout Example");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 400);

        JPanel panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));

        panel.add(new JButton("Botão 1"));
        panel.add(Box.createRigidArea(new Dimension(0, 20))); // Espaço fixo
        panel.add(new JButton("Botão 2"));
        panel.add(Box.createVerticalGlue()); // Espaço flexível
        panel.add(new JButton("Botão 3"));
        panel.add(Box.createRigidArea(new Dimension(0, 10)));
        panel.add(new JButton("Botão 4"));
        panel.add(Box.createVerticalGlue());
        panel.add(new JButton("Botão 5"));

        frame.add(panel);
        frame.setVisible(true);
    }
}

