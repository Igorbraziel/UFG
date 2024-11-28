package Task_GraphicalInterface_Swing;

import javax.swing.*;
import javax.swing.border.Border;
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
        contentPanel.add(panelWindow2);
        contentPanel.add(Box.createRigidArea(new Dimension(0, 20)));

        //CREATING THIRD PANEL
        PanelWindow panelWindow3 = new PanelWindow();
        panelWindow3.createPanelWindow3();
        contentPanel.add(panelWindow3);
        contentPanel.add(Box.createRigidArea(new Dimension(0, 20)));

        //CREATING FOURTH PANEL
        PanelWindow panelWindow4 = new PanelWindow();
        panelWindow4.createPanelWindow4();
        contentPanel.add(panelWindow4);
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
