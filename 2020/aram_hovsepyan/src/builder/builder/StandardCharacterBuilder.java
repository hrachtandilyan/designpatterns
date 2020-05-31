package builder.builder;

import bridge.armour.Armour;
import bridge.weapon.Weapon;

import java.util.List;
import java.util.function.Consumer;

public class StandardCharacterBuilder implements CharacterBuilder {

    private Character character;

    public StandardCharacterBuilder() {
        character = new Character();
    }

    @Override
    public CharacterBuilder health(int health) {
        character.health = health;
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
        return this;
    }

    @Override
    public CharacterBuilder gauntlets(Armour gauntlets) {
        character.gauntlets = gauntlets;
        return this;
    }

    @Override
    public CharacterBuilder chestArmour(Armour chestArmour) {
        character.chestArmour = chestArmour;
        return this;
    }

    @Override
    public CharacterBuilder legArmour(Armour legArmour) {
        character.legArmour = legArmour;
        return this;
    }

    @Override
    public CharacterBuilder primaryWeapon(Weapon primaryWeapon) {
        character.primaryWeapon = primaryWeapon;
        return this;
    }

    @Override
    public CharacterBuilder secondaryWeapon(Weapon secondaryWeapon) {
        character.secondaryWeapon = secondaryWeapon;
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
