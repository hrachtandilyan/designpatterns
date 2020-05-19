package bridge.armour;

public abstract class Armour {

    protected int defence;
    protected int armourHealth;

    protected Armour(int defence) {
        this.defence = defence;
        this.armourHealth = 100;
    }

    public int defendAndGetDamage(int damage) {
        int damageAfterDefence = damage - defence;
        armourHealth -= damageAfterDefence;
        effectsOnHit(damage);
        return damageAfterDefence;
    }

    public int getDefence() {
        return defence;
    }

    public void setDefence(int defence) {
        this.defence = defence;
    }

    public int getArmourHealth() {
        return armourHealth;
    }

    public void setArmourHealth(int armourHealth) {
        this.armourHealth = armourHealth;
    }

    protected abstract void effectsOnHit(int damage);

}
