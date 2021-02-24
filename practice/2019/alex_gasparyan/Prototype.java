class Test {

    static HashMap<String, Shape> mapping = new HashMap<>();

    public static void main(String[] args) {
        mapping.put("Rectangle", new Rectangle());
        mapping.put("Oval", new Oval());

        Shape shallowCopy = (Shape) mapping.get("Oval").clone();
        shallowCopy.draw();//will draw oval
    }
}

abstract class Shape implements Cloneable {
    abstract void draw();

    @Override
    protected Object clone() {
        Object clone = null;
        try {
            clone = super.clone();
        }
        catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }
        return clone;
    }
}

class Rectangle extends Shape {

    @Override
    void draw() {
    }
}

class Oval extends Shape {

    @Override
    void draw() {
    }
}