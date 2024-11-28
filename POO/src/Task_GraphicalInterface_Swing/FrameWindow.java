package Task_GraphicalInterface_Swing;

import javax.swing.*; // utilização de classes o pacote swing.

import java.awt.*;

public class FrameWindow extends JFrame {
    public FrameWindow(){
        this.setResizable(false);
        this.setLayout(new FlowLayout());
    }

    public void executeApplication(){
        this.setSize(650, 700);
        this.setVisible(true);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
