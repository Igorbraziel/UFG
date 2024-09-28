package Musicas_Compositores;

import java.util.List;
import java.util.ArrayList;

public class Compositor {
    public String name;
    public String nationality;
    public List<Musica> musicList = new ArrayList<>();

    public Compositor(String name, String nationality){
        this.name = name;
        this.nationality = nationality;
    }

    public void addMusic(Musica music){
        this.musicList.add(music);
    }

    public String showMusics(){
        String musicStr = "";
        for(Musica music : this.musicList){
            musicStr += "       " + music.name + " " + music.createdYear + " " + music.musicType + "\n";
        }
        return musicStr += "    }\n";
    }

    public String toString(){
        return "Nome: " + this.name + "\n"
        + "Nacionalidade: " + this.nationality + "\n"
        + "Musicas do Compositor:{ \n" + this.showMusics();  
    }
}
