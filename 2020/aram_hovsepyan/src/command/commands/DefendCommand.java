package command.commands;

import command.Character;

public class DefendCommand implements Command {

    private Character character;
    private int lastDefence;

    public DefendCommand(Character character) {
        this.character = character;
        this.lastDefence = -1;
    }

    @Override
    public void execute() {
        lastDefence = character.health;
        character.health = 100;
    }

    @Override
    public void undo() {
        if (lastDefence == -1) {
            return;
        }
        character.health = lastDefence;
    }

}
