package command.commands;

public interface Command {

    void execute();

    default void undo() {
        throw new UnsupportedOperationException(String.format("Undo is not supported for %s class", getClass().getSimpleName()));
    }

}
