package builder.builder;

import bridge.armour.Armour;
import bridge.weapon.Weapon;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

public class Character {

    int health;
    List<Object> backpack;
    Armour helmet;
    Armour gauntlets;
    Armour chestArmour;
    Armour legArmour;
    Weapon primaryWeapon;
    Weapon secondaryWeapon;
    Consumer<Character> ability;

    Character() {
        backpack = new ArrayList<>();
    }

    public void activateAbility() {
        if (ability == null) {
            System.out.println("Character has no ability");
            return;
        }
        ability.accept(this);
    }

    public int getHealth() {
        return health;
    }

    public void setHealth(int health) {
        this.health = health;
    }

    public List<Object> getBackpack() {
        return backpack;
    }

    public Armour getHelmet() {
        return helmet;
    }

    public Armour getGauntlets() {
        return gauntlets;
    }

    public Armour getChestArmour() {
        return chestArmour;
    }

    public Armour getLegArmour() {
        return legArmour;
    }

    public Weapon getPrimaryWeapon() {
        return primaryWeapon;
    }

    public Weapon getSecondaryWeapon() {
        return secondaryWeapon;
    }

    public Consumer<Character> getAbility() {
        return ability;
    }

}
