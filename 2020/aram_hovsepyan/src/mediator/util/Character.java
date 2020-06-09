package mediator.util;

import mediator.Notifier;

import java.util.function.Consumer;

public class Character {

    public Vector2 position;
    private float health;

    public Character() {
        this.position = new Vector2();
        this.health = 100f;
        Consumer<Vector2> aoeConsumer = aoeCenter -> {
            if (position == aoeCenter) { // filter out character himself
                return;
            }
            float distance = distance(aoeCenter);
            if (distance > 10f) {
                return;
            }
            health -= (10f - distance) * 10f;
        };
        Notifier.getInstance().subscribe("AoE", aoeConsumer);
    }

    public void doAoE() {
        Notifier.getInstance().publish("AoE", position);
    }

    private float distance(Vector2 other) {
        return Math.abs((position.x - other.x) * (position.x - other.x) + (position.y - other.y) * (position.y - other.y));
    }

}
