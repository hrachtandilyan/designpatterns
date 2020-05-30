package prototype.prototype;

public interface Creature {

    int getHealth();

    void takeDamage(int damage);

    Creature copy();

}
