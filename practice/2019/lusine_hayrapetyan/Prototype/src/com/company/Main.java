package com.company;

public class Main {

    public static void main(String[] args) {
        Square square = new Square();
        Circle circle = new Circle();

        Shape shape = (Shape)square.clone();
        shape.draw();
    }
}
