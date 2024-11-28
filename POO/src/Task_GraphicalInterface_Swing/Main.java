package Task_GraphicalInterface_Swing;

import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.border.TitledBorder;
import java.awt.*;
import java.util.Locale;

public class Main {
    public static void main(String[] args){
        Locale.setDefault(Locale.US);
        FrameWindow myFrame = new FrameWindow();

        // CREATING MENU BAR
        MenuBarWindow myMenuBar = new MenuBarWindow();
        myFrame.setJMenuBar(myMenuBar);

        // CREATING CONTENT PANEL
        PanelWindow contentPanel = new PanelWindow();
        contentPanel.setLayout(new BoxLayout(contentPanel, BoxLayout.Y_AXIS));

        // CREATING FIRST PANEL
        PanelWindow panelWindow1 = new PanelWindow();
        panelWindow1.createPanelWindow1();
        contentPanel.add(panelWindow1);
        contentPanel.add(Box.createRigidArea(new Dimension(0, 20)));


        // CREATING SECOND PANEL
        PanelWindow panelWindow2 = new PanelWindow();
        panelWindow2.createPanelWindow2();
        TitledBorder panel2Border = BorderFactory.createTitledBorder("");
        panel2Border.setTitleColor(Color.BLUE);
        panelWindow2.setBorder(panel2Border);
        contentPanel.add(panelWindow2);
        contentPanel.add(Box.createRigidArea(new Dimension(0, 20)));

        //CREATING THIRD PANEL
        PanelWindow textAreaPanel = new PanelWindow();
        textAreaPanel.createTextAreaPanel();
        TitledBorder textAreaBorder = BorderFactory.createTitledBorder("Curriculum Vitae");
        textAreaBorder.setTitleColor(Color.BLUE);
        textAreaPanel.setBorder(textAreaBorder);
        contentPanel.add(textAreaPanel);
        contentPanel.add(Box.createRigidArea(new Dimension(0, 20)));

        //CREATING FOURTH PANEL
        PanelWindow areaPanel = new PanelWindow();
        areaPanel.createAreaPanel();
        TitledBorder areaBorder = BorderFactory.createTitledBorder("Áreas");
        areaBorder.setTitleColor(Color.BLUE);
        areaPanel.setBorder(areaBorder);
        contentPanel.add(areaPanel);
        contentPanel.add(Box.createRigidArea(new Dimension(0, 20)));

        //CREATING FIFTH PANEL
        PanelWindow panelWindow5 = new PanelWindow();
        panelWindow5.createPanelWindow5();
        contentPanel.add(panelWindow5);
        contentPanel.add(Box.createRigidArea(new Dimension(0, 20)));

        myFrame.add(contentPanel);

        myFrame.executeApplication();
    }
}
