package Musicas_Compositores;

import java.util.List;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        List<Compositor> composerList = new ArrayList<>();
        List<Musica> musicList = new ArrayList<>();

        composerList.add(new Compositor("Nome 1", "Nacionalidade 1"));
        composerList.add(new Compositor("Nome 2", "Nacionalidade 2"));
        composerList.add(new Compositor("Nome 3", "Nacionalidade 3"));
        composerList.add(new Compositor("Nome 4", "Nacionalidade 4"));
        composerList.add(new Compositor("Nome 5", "Nacionalidade 5"));
        composerList.add(new Compositor("Nome 6", "Nacionalidade 6"));

        musicList.add(new Musica("Musica 1", 2000, "Tipo 1", composerList.stream().filter(x -> x.name == "Nome 1").findFirst().orElse(null)));
        musicList.add(new Musica("Musica 2", 2001, "Tipo 1", composerList.stream().filter(x -> x.name == "Nome 1").findFirst().orElse(null)));
        musicList.add(new Musica("Musica 3", 2002, "Tipo 2", composerList.stream().filter(x -> x.name == "Nome 1").findFirst().orElse(null)));
        musicList.add(new Musica("Musica 4", 2003, "Tipo 2", composerList.stream().filter(x -> x.name == "Nome 2").findFirst().orElse(null)));
        musicList.add(new Musica("Musica 5", 2004, "Tipo 3", composerList.stream().filter(x -> x.name == "Nome 2").findFirst().orElse(null)));
        musicList.add(new Musica("Musica 6", 2005, "Tipo 3", composerList.stream().filter(x -> x.name == "Nome 2").findFirst().orElse(null)));

        for(Musica music : musicList){
            for(Compositor composer : composerList){
                composer.addMusic(music);
            }
        }

        for(Musica music : musicList){
            System.out.println(music);
        }

    }
}
