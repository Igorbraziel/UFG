package Task_GraphicalInterface_Swing;

import javax.swing.*; // utilização de classes o pacote swing.

import java.awt.*;

public class FrameWindow extends JFrame {
    public FrameWindow(){
        this.setResizable(false);
    }

    public void executeApplication(){
        this.setSize(600, 600);
        this.setVisible(true);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
