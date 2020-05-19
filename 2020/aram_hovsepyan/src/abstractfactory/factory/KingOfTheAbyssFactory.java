package abstractfactory.factory;

import abstractfactory.armour.Armour;
import abstractfactory.armour.ShieldOfTheAbyss;
import abstractfactory.weapon.SwordOfTheAbyss;
import abstractfactory.weapon.Weapon;

import java.util.ArrayList;
import java.util.Arrays;

public class KingOfTheAbyssFactory implements BossFactory {

    @Override
    public Weapon createWeapon() {
        return new SwordOfTheAbyss(Integer.MAX_VALUE, new ArrayList<>());
    }

    @Override
    public Armour createArmour() {
        return new ShieldOfTheAbyss(Integer.MAX_VALUE / 2, Arrays.asList(12351425, 12345137));
    }

}
