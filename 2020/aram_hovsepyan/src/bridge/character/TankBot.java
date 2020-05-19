package bridge.character;

import bridge.armour.Armour;
import bridge.weapon.Weapon;

public class TankBot extends Bot {

    public TankBot(Weapon weapon, Armour armour) {
        super(weapon, armour);
    }

    @Override
    public void activateAbility() {
        armour.setDefence(armour.getDefence() * 3);
    }

    @Override
    public void disableAbility() {
        armour.setDefence(armour.getDefence() / 3);
    }

}
