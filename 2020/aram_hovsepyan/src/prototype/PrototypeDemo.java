package prototype;

import prototype.prototype.Creature;
import prototype.prototype.Slime;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.stream.IntStream;

public class PrototypeDemo {

    public static void main(String[] args) {
        Random rand = new Random();
        List<Creature> world = new ArrayList<>();
        IntStream.range(0, 100).forEach(i -> world.add(new Slime()));
        while (!world.isEmpty()) {
            int index = rand.nextInt(world.size());
            int damage = rand.nextInt(100);
            Creature creature = world.get(index);
            creature.takeDamage(damage);
            System.out.print(String.format("Creature #%d took %d damage", index, damage));
            int health = creature.getHealth();
            if (health > 0 && health < 50) {
                world.add(creature.copy());
                System.out.println(" and spawned it's copy");
            } else if (health <= 0) {
                world.remove(index);
                System.out.println(" and died");
            } else {
                System.out.println();
            }
            System.out.println(String.format("%d creatures left", world.size()));
            System.out.println();
        }
    }
}
