package builder.builder;

import bridge.armour.Armour;
import bridge.weapon.Weapon;

import java.util.List;
import java.util.function.Consumer;

public class BuffedCharacterBuilder implements CharacterBuilder {

    private Character character;

    public BuffedCharacterBuilder() {
        this.character = new Character();
        character.health = 100;
    }

    @Override
    public CharacterBuilder health(int health) {
        return this;
    }

    @Override
    public CharacterBuilder backpack(List<Object> backpack) {
        character.backpack = backpack;
        return this;
    }

    @Override
    public CharacterBuilder helmet(Armour helmet) {
        character.helmet = helmet;
        character.helmet.setArmourHealth(100);
        character.helmet.setDefence(character.helmet.getDefence() * 2);
        return this;
    }

    @Override
    public CharacterBuilder gauntlets(Armour gauntlets) {
        character.gauntlets = gauntlets;
        character.gauntlets.setArmourHealth(100);
        character.gauntlets.setDefence(character.gauntlets.getDefence() * 2);
        return this;
    }

    @Override
    public CharacterBuilder chestArmour(Armour chestArmour) {
        character.chestArmour = chestArmour;
        character.chestArmour.setArmourHealth(100);
        character.chestArmour.setDefence(character.chestArmour.getDefence() * 2);
        return this;
    }

    @Override
    public CharacterBuilder legArmour(Armour legArmour) {
        character.legArmour = legArmour;
        character.legArmour.setArmourHealth(100);
        character.legArmour.setDefence(character.legArmour.getDefence() * 2);
        return this;
    }

    @Override
    public CharacterBuilder primaryWeapon(Weapon primaryWeapon) {
        character.primaryWeapon = primaryWeapon;
        character.primaryWeapon.setDamage(character.primaryWeapon.getDamage() * 2);
        return this;
    }

    @Override
    public CharacterBuilder secondaryWeapon(Weapon secondaryWeapon) {
        character.secondaryWeapon = secondaryWeapon;
        character.secondaryWeapon.setDamage(character.secondaryWeapon.getDamage() * 2);
        return this;
    }

    @Override
    public CharacterBuilder ability(Consumer<Character> ability) {
        character.ability = ability;
        return this;
    }

    @Override
    public Character build() {
        return character;
    }

}
