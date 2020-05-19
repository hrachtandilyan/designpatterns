package abstractfactory.factory;

import abstractfactory.armour.Armour;
import abstractfactory.armour.DarknessGauntlets;
import abstractfactory.weapon.DarknessLauncher;
import abstractfactory.weapon.Weapon;

public class LightDestroyerFactory implements BossFactory {

    @Override
    public Weapon createWeapon() {
        return new DarknessLauncher(Integer.MAX_VALUE / 8);
    }

    @Override
    public Armour createArmour() {
        return new DarknessGauntlets(Integer.MAX_VALUE / 16);
    }

}
