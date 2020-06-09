package decorator.decorators;

import decorator.characters.Character;

public class AdrenalinShot extends CharacterDecorator {

    public AdrenalinShot(Character character) {
        super(character);
    }

    @Override
    public int getBuff() {
        return 10;
    }

}
