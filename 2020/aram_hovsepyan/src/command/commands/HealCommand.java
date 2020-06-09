package command.commands;

import command.Character;

public class HealCommand implements Command {

    private Character character;
    private int lastHealth;

    public HealCommand(Character character) {
        this.character = character;
        this.lastHealth = -1;
    }

    @Override
    public void execute() {
        lastHealth = character.health;
        character.health = 100;
    }

    @Override
    public void undo() {
        if (lastHealth == -1) {
            return;
        }
        character.health = lastHealth;
    }

}
