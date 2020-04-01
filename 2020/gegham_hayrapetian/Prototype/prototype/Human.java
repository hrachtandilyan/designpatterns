package com.rau.prototype;

public class Human implements Copyable<Human> {
    public int age;
    public String name;

    @Override
    public String toString() {
        return "Human{" +
                "age=" + age +
                ", name='" + name + '\'' +
                '}';
    }

    @Override
    public Human copy() {
        Human copy = new Human(age, name);
        return copy;
    }

    public Human(int age, String name) {
        this.age = age;
        this.name = name;
    }


}
