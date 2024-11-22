package Task_JUnitTests;

public class TransformaNome {
    String nome;

    TransformaNome(String nome) {
        this.nome = nome;
    }

    String maiusculo() {
        return nome.toUpperCase();
    }

    String minusculo() {
        return nome.toLowerCase();
    }

    int buscarBranco() {
        int qtde = 0;
        int i = 0;
        int pos = 0;
        while (pos >= 0) {
            pos = nome.indexOf(' ', i);
            if (pos >= 0) {
                qtde++;
                i = pos + 1;
            }
        }
        return qtde;
    }

    String nomeInvertido(){
        String newName = "";
        for(int i = nome.length() - 1; i >= 0; i--){
            newName += nome.charAt(i);
        }
        return newName;
    }

    int quantidadePalavras(){
        return buscarBranco() + 1;
    }
}
