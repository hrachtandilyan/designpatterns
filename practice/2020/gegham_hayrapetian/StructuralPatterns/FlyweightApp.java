import java.util.*;

public class FlyweightApp {

    public static void main(String[] args) {
        ShapeFactory shapeFactory = new ShapeFactory();
        List<Shape> shapes = new ArrayList<>();
        shapes.add(shapeFactory.getShape("square"));
        shapes.add(shapeFactory.getShape("circle"));
        shapes.add(shapeFactory.getShape("circle"));
        shapes.add(shapeFactory.getShape("point"));
        shapes.add(shapeFactory.getShape("square"));
        shapes.add(shapeFactory.getShape("circle"));
        Random random = new Random();
        for (Shape shape : shapes) {
            int x = random.nextInt(100);
            int y = random.nextInt(100);
            shape.draw(x, y);

        }
        Runtime runtime = Runtime.getRuntime();
        // Run the garbage collector
        runtime.gc();
        // Calculate the used memory
        long memory = runtime.totalMemory() - runtime.freeMemory();
        System.out.println("Used memory is bytes: " + memory);
    }
}

//Flyweight
interface Shape {
    void draw(int x, int y);
}

//Point Flyweight
class Point implements Shape {

    @Override
    public void draw(int x, int y) {
        System.out.println("(" + x + "," + y + ") : draw a point");
    }
}

//Circle Flyweight
class Circle implements Shape {
    int r = 5;

    @Override
    public void draw(int x, int y) {
        System.out.println("(" + x + "," + y + ") : draw a circle with radius " + r);
    }
}

//Square Flyweight
class Square implements Shape {
    int a = 10;

    @Override
    public void draw(int x, int y) {
        System.out.println("(" + x + "," + y + ") : draw a square with edge " + a);
    }
}

class ShapeFactory {
    private static final Map<String, Shape> shapes = new LinkedHashMap<>();

    public Shape getShape(String shapeName) {
        Shape shape = shapes.get(shapeName);
        if (shape == null) {
            switch (shapeName) {
                case "circle":
                    shape = new Circle();
                    break;
                case "square":
                    shape = new Square();
                    break;
                case "point":
                    shape = new Point();
                    break;
            }
            shapes.put(shapeName, shape);
        }
        return shape;
    }
}

