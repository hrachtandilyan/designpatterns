package com.rau;

public class Facade {

    public static void main(String[] args) {
        Computer computer = new Computer();
        computer.copy();

    }


}

class Computer {
    Power power = new Power();
    DVDROm dvd = new DVDROm();
    SDD ssd = new SDD();

    void copy() {
        power.on();
        dvd.load();
        ssd.copyFromDVD(dvd);
    }

}

class Power {
    void on() {
        System.out.println("Питание включено");
    }

    void off() {
        System.out.println("Питание выключено");
    }
}

class DVDROm {
    private boolean data = false;

    public boolean hasData() {
        return data;
    }

    void load() {
        data = true;

    }

    void unload() {

        data = false;

    }
}

class SDD {
    void copyFromDVD(DVDROm dvd) {
        if (dvd.hasData()) {
            System.out.println("Копируются данные с диска.");

        } else {
            System.out.println("Вставьте диск.");
        }
    }
}
