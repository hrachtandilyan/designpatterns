package singleton;

import singleton.singleton.Entity;
import singleton.singleton.UniqueKeyGenerator;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.IntStream;

public class SingletonDemo {

    public static void main(String[] args) {
        List<Entity> entities = new ArrayList<>();
        IntStream.range(0, 100).forEach(i -> entities.add(new Entity(UniqueKeyGenerator.getInstance().generateKey())));
        entities.stream().map(Entity::toString).forEach(System.out::println);
    }

}
