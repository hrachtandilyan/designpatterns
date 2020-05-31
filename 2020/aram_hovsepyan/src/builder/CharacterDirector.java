package builder;

import bridge.armour.StandardArmour;
import bridge.armour.TankArmour;
import bridge.weapon.MachineGun;
import bridge.weapon.Shotgun;
import builder.builder.Character;
import builder.builder.CharacterBuilder;

public class CharacterDirector {

    private CharacterBuilder builder;

    public CharacterDirector(CharacterBuilder builder) {
        this.builder = builder;
    }

    public void setBuilder(CharacterBuilder builder) {
        this.builder = builder;
    }

    public Character createStandardCharacter() {
        builder.health(100);

        builder.helmet(new StandardArmour(11));
        builder.gauntlets(new StandardArmour(22));
        builder.chestArmour(new StandardArmour(99));
        builder.legArmour(new StandardArmour(77));

        builder.primaryWeapon(new Shotgun(33));

        return builder.build();
    }

    public Character createTankCharacter() {
        builder.health(100);

        builder.helmet(new TankArmour(333));
        builder.gauntlets(new TankArmour(222));
        builder.chestArmour(new TankArmour(999));
        builder.legArmour(new TankArmour(777));

        builder.primaryWeapon(new Shotgun(333));
        builder.secondaryWeapon(new MachineGun(111));

        builder.ability(character -> {
            character.setHealth(100);
            character.getHelmet().setArmourHealth(100);
            character.getGauntlets().setArmourHealth(100);
            character.getChestArmour().setArmourHealth(100);
            character.getLegArmour().setArmourHealth(100);
        });

        return builder.build();
    }

}
