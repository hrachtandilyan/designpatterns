package com.rau;

public class MementoApp {
    public static void main(String[] args) {
        Game game = new Game();
        game.set("Lvl_1", 3000);
        System.out.println(game);

        File file = new File();
        file.setSave(game.save());

        game.set("Lvl_2", 5500);
        System.out.println(game);

        
        game.load(file.getSave());
        System.out.println(game);

    }
}

class Game {
    private String level;
    private int ms;

    public void set(String level, int ms) {
        this.level = level;
        this.ms = ms;

    }

    public void load(Save save) {
        level = save.getLevel();
        ms = save.getMs();
    }

    public Save save() {
        return new Save(level, ms);
    }

    @Override
    public String toString() {
        return "Game{" +
                "level='" + level + '\'' +
                ", ms=" + ms +
                '}';
    }
}

class Save {
    private final String level;
    private final int ms;

    public Save(String level, int ms) {
        this.level = level;
        this.ms = ms;

    }

    public String getLevel() {
        return level;
    }

    public int getMs() {
        return ms;
    }
}

class File {
    public Save save;

    public Save getSave() {
        return save;
    }

    public void setSave(Save save) {
        this.save = save;
    }
}