package decorator.decorators;

import decorator.characters.Character;

import java.util.Random;

public class SurpriseBeverage extends CharacterDecorator {

    private Random random;

    public SurpriseBeverage(Character character) {
        super(character);
        this.random = new Random();
    }

    @Override
    public int getBuff() {
        return 5 + random.nextInt(145);
    }

}
