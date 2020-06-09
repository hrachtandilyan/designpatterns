package decorator.decorators;

import decorator.characters.Character;

public abstract class CharacterDecorator implements Character {

    private Character character;

    public CharacterDecorator(Character character) {
        this.character = character;
    }

    @Override
    public int getPower() {
        return character.getPower() + getBuff();
    }

    protected abstract int getBuff();

}
