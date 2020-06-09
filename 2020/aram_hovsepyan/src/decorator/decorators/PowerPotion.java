package decorator.decorators;

import decorator.characters.Character;

public class PowerPotion extends CharacterDecorator {

    public PowerPotion(Character character) {
        super(character);
    }

    @Override
    public int getBuff() {
        return 50;
    }

}
