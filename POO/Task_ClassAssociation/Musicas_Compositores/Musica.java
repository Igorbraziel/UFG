package Musicas_Compositores;

import java.util.List;
import java.util.ArrayList;

public class Musica{
    public String name;
    public int createdYear;
    public String musicType;
    public List<Compositor> composerList = new ArrayList<>(); 

    public Musica(String name, int createdYear, String musicType, Compositor composer){
        this.name = name;
        this.createdYear = createdYear;
        this.musicType = musicType;
        this.composerList.add(composer);
    }

    public String showComposers(){
        String composerStr = "";
        for(Compositor composer : this.composerList){
            composerStr += composer.toString();
        }
        return composerStr;
    }

    public String toString(){
        return "Nome: " + this.name + "\n"
        + "Ano: " + this.createdYear + "\n"
        + "Tipo: " + this.musicType + "\n"
        + "Compositores:{ \n"
        + this.showComposers() + "} \n";  
    }
}