package Task_GraphicalInterface_Swing;

import javax.swing.*; // utilização de classes o pacote swing.

import java.awt.*;

public class PanelWindow extends JPanel {
    private LayoutManager layoutManager;

    public PanelWindow(){

    }

    public PanelWindow(LayoutManager layoutManager){
        this.layoutManager = layoutManager;
        this.setLayout(layoutManager);
    }

    public void createPanelWindow1(){
        this.setLayoutManager(new FlowLayout(FlowLayout.CENTER));
        this.setSize(600, 50);
        JLabel label = new JLabel("Ficha de Avaliação", JLabel.CENTER);
        label.setSize(600, 50);
        this.add(label);
        this.setVisible(true);
    }

    public void createPanelWindow2(){
        this.setLayoutManager(new GridLayout(1, 2));
        this.setSize(600, 150);

        PanelWindow newPanel1 = new PanelWindow(new GridLayout(3, 1));
        JLabel label1 = new JLabel("Código:", JLabel.LEFT);
        JLabel label2 = new JLabel("Nome:", JLabel.LEFT);
        JLabel label3 = new JLabel("Sexo:", JLabel.LEFT);
        newPanel1.add(label1);
        newPanel1.add(label2);
        newPanel1.add(label3);

        PanelWindow newPanel2 = new PanelWindow(new GridLayout(3, 1, 0, 15));
        JTextField textField1 = new JTextField();
        JTextField textField2 = new JTextField();
        PanelWindow radioButtonPanel = new PanelWindow();
        JRadioButton radioButton1 = new JRadioButton("Feminino");
        JRadioButton radioButton2 = new JRadioButton("Masculino");
        radioButtonPanel.add(radioButton1);
        radioButtonPanel.add(radioButton2);
        newPanel2.add(textField1);
        newPanel2.add(textField2);
        newPanel2.add(radioButtonPanel);

        this.add(newPanel1);
        this.add(newPanel2);
        this.setVisible(true);
    }

    public void createPanelWindow3(){
        this.setLayoutManager(new FlowLayout(FlowLayout.CENTER));
        this.setSize(600, 200);

        JTextArea textArea = new JTextArea("", 5, 50);
        JScrollPane scrollPane = new JScrollPane(textArea, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        this.add(scrollPane);
        this.setVisible(true);
    }

    public LayoutManager getLayoutManager() {
        return layoutManager;
    }

    public void setLayoutManager(LayoutManager layoutManager) {
        this.layoutManager = layoutManager;
        this.setLayout(layoutManager);
    }
}
