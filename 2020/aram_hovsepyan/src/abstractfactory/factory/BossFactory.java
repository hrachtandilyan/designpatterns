package abstractfactory.factory;

import abstractfactory.armour.Armour;
import abstractfactory.weapon.Weapon;

public interface BossFactory {

    Weapon createWeapon();

    Armour createArmour();

}
