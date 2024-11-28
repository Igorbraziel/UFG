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
        JLabel label = new JLabel("Ficha de Avaliação", JLabel.CENTER);
        label.setForeground(Color.RED);
        this.add(label);
        this.setVisible(true);
    }

    public void createPanelWindow2(){
        this.setLayoutManager(new GridLayout(1, 2));

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

    public void createTextAreaPanel(){
        this.setLayoutManager(new FlowLayout(FlowLayout.CENTER));

        JTextArea textArea = new JTextArea("", 8, 53);
        JScrollPane scrollPane = new JScrollPane(textArea, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        this.add(scrollPane);
        this.setVisible(true);
    }

    public void createAreaPanel(){
        this.setLayoutManager(new GridLayout(2, 2, 10, 20));
        this.setMinimumSize(new Dimension(600, 100));
        JLabel label1 = new JLabel("Interesse:");
        label1.setLayout(new FlowLayout(FlowLayout.LEFT));

        JLabel label2 = new JLabel("Atuação:");
        label2.setLayout(new FlowLayout(FlowLayout.LEFT));

        this.add(label1);
        this.add(label2);

        String[] comboBoxData1 = {"Desenvolvedor"};
        JComboBox<String> comboBox1 = new JComboBox<String>(comboBoxData1);
        comboBox1.setForeground(Color.RED);
        JScrollPane scrollPane1 = new JScrollPane(comboBox1);

        String[] comboBoxData2 = {"Programação"};
        JComboBox<String> comboBox2 = new JComboBox<String>(comboBoxData2);
        comboBox2.setForeground(Color.BLUE);
        JScrollPane scrollPane2 = new JScrollPane(comboBox2);

        this.add(scrollPane1);
        this.add(scrollPane2);
    }

    public void createPanelWindow5(){
        this.setLayout(new FlowLayout(FlowLayout.CENTER, 0, 10));
        this.setBackground(new Color(48, 210, 27));
        this.setMaximumSize(new Dimension(600, 10));
        PanelWindow buttonPanel = new PanelWindow(new GridLayout(1, 5, 10, 0));
        buttonPanel.setBackground(new Color(48, 210, 27));
        JButton button1 = new JButton("Salvar");
        JButton button2 = new JButton("Anterior");
        JButton button3 = new JButton("Próximo");
        JButton button4 = new JButton("Novo");
        JButton button5 = new JButton("Cancelar");

        buttonPanel.add(button1);
        buttonPanel.add(button2);
        buttonPanel.add(button3);
        buttonPanel.add(button4);
        buttonPanel.add(button5);
        this.add(buttonPanel);
    }

    public LayoutManager getLayoutManager() {
        return layoutManager;
    }

    public void setLayoutManager(LayoutManager layoutManager) {
        this.layoutManager = layoutManager;
        this.setLayout(layoutManager);
    }
}