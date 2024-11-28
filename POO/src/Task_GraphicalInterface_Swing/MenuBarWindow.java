package Task_GraphicalInterface_Swing;

import javax.swing.*; // utilização de classes o pacote swing.

import java.awt.*;
import java.util.ArrayList;
import java.util.List;

public class MenuBarWindow extends JMenuBar {
    private FlowLayout layoutManager = new FlowLayout(FlowLayout.LEFT);

    public MenuBarWindow(){
        this.createMenu();
        this.setLayout(layoutManager);
    }

    public void createMenu(){
        MenuWindow menuWindow1 = new MenuWindow("Arquivo");

        MenuItemWindow menuItemWindow1 = new MenuItemWindow("Enviar");
        MenuItemWindow subItem1 = new MenuItemWindow("email");
        MenuItemWindow subItem2 = new MenuItemWindow("impressora");
        menuItemWindow1.add(subItem1);
        menuItemWindow1.add(subItem2);
        MenuItemWindow menuItemWindow2 = new MenuItemWindow("Salvar");
        MenuItemWindow menuItemWindow3 = new MenuItemWindow("Sair");

        menuWindow1.add(menuItemWindow1);
        menuWindow1.add(menuItemWindow2);
        menuWindow1.add(menuItemWindow3);

        MenuWindow menuWindow2 = new MenuWindow("Editar");

        this.add(menuWindow1);
        this.add(menuWindow2);

        setVisible(true);
    }
}
