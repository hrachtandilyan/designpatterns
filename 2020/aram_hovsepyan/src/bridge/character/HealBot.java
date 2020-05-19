package bridge.character;

import bridge.armour.Armour;
import bridge.weapon.Weapon;

public class HealBot extends Bot {

    protected HealBot(Weapon weapon, Armour armour) {
        super(weapon, armour);
    }

    @Override
    public void activateAbility() {
        health = 100;
        armour.setArmourHealth(100);
    }

    @Override
    public void disableAbility() {

    }

}
