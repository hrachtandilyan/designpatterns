package bridge.weapon;

public abstract class Weapon {

    protected int damage;

    protected Weapon(int damage) {
        this.damage = damage;
    }

    public int getDamage() {
        return damage;
    }

    public void setDamage(int damage) {
        this.damage = damage;
    }

    public abstract void shoot();

}
