package Task_GraphicalInterface_Swing;

import javax.swing.*;
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
        PanelWindow contentPanel = new PanelWindow(new GridLayout(5, 1, 0, 0));

        // CREATING FIRST PANEL
        PanelWindow panelWindow1 = new PanelWindow();
        panelWindow1.createPanelWindow1();
        contentPanel.add(panelWindow1);

        // CREATING SECOND PANEL
        PanelWindow panelWindow2 = new PanelWindow();
        panelWindow2.createPanelWindow2();
        contentPanel.add(panelWindow2);

        //CREATING THIRD PANEL
        PanelWindow panelWindow3 = new PanelWindow();
        panelWindow3.createPanelWindow3();
        contentPanel.add(panelWindow3);

        myFrame.add(contentPanel);

        myFrame.executeApplication();
    }
}
