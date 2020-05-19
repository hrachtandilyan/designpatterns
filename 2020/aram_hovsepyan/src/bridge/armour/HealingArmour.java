package bridge.armour;

import java.util.function.Consumer;

public class HealingArmour extends Armour {

    private final Consumer<Integer> healingConsumer;

    public HealingArmour(int defence, Consumer<Integer> healingConsumer) {
        super(defence);
        this.healingConsumer = healingConsumer;
    }

    @Override
    protected void effectsOnHit(int damage) {
        healingConsumer.accept(damage / 10);
    }

}
