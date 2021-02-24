public class GameConsoleFactory {
    public static GameConsole getComputer(GameConsoleAbstractFactory factory){
        return factory.createConsole();
    }
}
