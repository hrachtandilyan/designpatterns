package factorymethod.util;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class State {

    public int health;
    public int mana;
    public List<Object> items;

    public State() {
        health = 100;
        mana = 100;
        items = new ArrayList<>();
    }

    public State(int health, int mana, List<Object> items) {
        this.health = health;
        this.mana = mana;
        this.items = new ArrayList<>(items);
    }

    @Override
    public String toString() {
        return String.format("Health: %d; Mana: %d\nItems: %s", health, mana, items
                .stream()
                .map(Object::toString)
                .collect(Collectors.joining(", ")));
    }

}
