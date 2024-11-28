package Swing_Examples;

import javax.swing.*;

public class TesteMenuBar extends JFrame {
    private JMenuBar jmbBarraMenu;
    private JMenu jmArquivo;
    private JMenuItem jmiNovo;
    private JMenuItem jmiAbrir;
    private JMenuItem jmiFechar;
    private JMenuItem jmiSalvar;
    private JMenuItem jmiSair;
    public TesteMenuBar() {
        super("Teste de Menu");
        jmbBarraMenu=new JMenuBar();
        setJMenuBar(jmbBarraMenu);
        jmArquivo=new JMenu("Arquivo");
        jmbBarraMenu.add(jmArquivo);
        jmiNovo=new JMenuItem("Novo");
        jmArquivo.add(jmiNovo);
        jmiAbrir=new JMenuItem("Abrir",new ImageIcon("open.gif"));
        jmArquivo.add(jmiAbrir);
        jmiAbrir.setMnemonic(65);
        jmiFechar=new JMenuItem("Fechar");
        jmArquivo.add(jmiFechar);
        jmiSalvar=new JMenuItem("Salvar");
        jmArquivo.add(jmiSalvar);
        jmiSair=new JMenuItem("Sair");
        jmArquivo.add(jmiSair);
        pack(); setVisible(true);

    }
    public static void main(String[] args) {
        TesteMenuBar t = new TesteMenuBar();
    }
}
