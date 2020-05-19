package abstractfactory.weapon;

public class DarknessLauncher implements Weapon {

    private int damage;

    public DarknessLauncher(int damage) {
        this.damage = damage;
    }

    @Override
    public int getDamage() {
        return damage;
    }

    public void setDamage(int damage) {
        this.damage = damage;
    }

}
