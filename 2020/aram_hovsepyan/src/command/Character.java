package command;

import command.commands.Command;

public class Character {

    public int health;
    public int defence;
    private Command abilityCommand;

    public Character() {
        this(() -> {
        });
    }

    public Character(Command abilityCommand) {
        this.health = 100;
        this.defence = 0;
        this.abilityCommand = abilityCommand;
    }

    public void activateAbility() {
        abilityCommand.execute();
    }

    public void revertLastAbility() {
        try {
            abilityCommand.undo();
        } catch (UnsupportedOperationException e) {
            System.out.println("No effect taken");
        }
    }

    public void setAbilityCommand(Command abilityCommand) {
        this.abilityCommand = abilityCommand;
    }

}
