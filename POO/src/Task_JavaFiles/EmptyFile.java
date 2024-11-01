package Task_JavaFiles;

public class EmptyFile extends Exception {
    public EmptyFile(){
        super("O arquivo de entrada está vazio, impossível copia-lo");
    }
}
