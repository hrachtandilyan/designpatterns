package prototype.prototype;

public class Slime implements Creature {

    private int health;

    public Slime() {
        this.health = 100;
    }

    @Override
    public int getHealth() {
        return health;
    }

    @Override
    public void takeDamage(int damage) {
        health -= damage;
    }

    @Override
    public Creature copy() {
        Slime clone = new Slime();
        clone.health = health;
        return clone;
    }

}
