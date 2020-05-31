package builder.builder;

import bridge.armour.Armour;
import bridge.weapon.Weapon;

import java.util.List;
import java.util.function.Consumer;

public interface CharacterBuilder {

    CharacterBuilder health(int health);

    CharacterBuilder backpack(List<Object> backpack);

    CharacterBuilder helmet(Armour helmet);

    CharacterBuilder gauntlets(Armour gauntlets);

    CharacterBuilder chestArmour(Armour chestArmour);

    CharacterBuilder legArmour(Armour legArmour);

    CharacterBuilder primaryWeapon(Weapon primaryWeapon);

    CharacterBuilder secondaryWeapon(Weapon secondaryWeapon);

    CharacterBuilder ability(Consumer<Character> ability);

    /**
     * @return Returns final character built. Builder behaviour after building is undefined!
     */
    Character build();

}
