package com.rau;

import java.io.Serializable;

public class Proxy {
    public static void main(String[] args) {
        Image image = new RealImage( "D:/image?my.jpg");
        image.display();

    }

}
//Virtual Proxy
interface Image {
    void display();

}

class RealImage implements Image {
    String file;

    public RealImage(String file) {
        this.file = file;
        load();
    }

    void load() {
        System.out.println("Loading " + file);
    }

    @Override
    public void display() {
        System.out.println("Display " + file);

    }
}

class ProxyImage implements Image {
    String file;
    RealImage image;

    public ProxyImage(String file) {
        this.file = file;
    }


    @Override
    public void display() {
        if (image == null) {
            image = new RealImage(file);
        }
        image.display();

    }
}