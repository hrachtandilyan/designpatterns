package bridge.character;

import bridge.armour.Armour;
import bridge.weapon.Weapon;

/**
 * This represents bridge.
 */
public abstract class Bot {

    protected Weapon weapon;
    protected Armour armour;
    protected int health;

    protected Bot(Weapon weapon, Armour armour) {
        this.weapon = weapon;
        this.armour = armour;
        this.health = 100;
    }

    public void attack(Bot bot) {
        weapon.shoot();
        bot.takeDamage(weapon.getDamage());
    }

    public void takeDamage(int damage) {
        health -= armour.defendAndGetDamage(damage);
    }

    public abstract void activateAbility();

    public abstract void disableAbility();

}
