package factorymethod;

import factorymethod.bot.AggressiveBot;
import factorymethod.bot.Bot;
import factorymethod.bot.SmartBot;
import factorymethod.util.State;

import java.util.Arrays;

public class Demo {

    public static void main(String[] args) {
        Bot bot1 = new SmartBot(new State(50, 60, Arrays.asList("Magic Wand", "Gun")));
        Bot bot2 = new AggressiveBot(new State(75, 10, Arrays.asList("Axe", "Shield")));
        bot1.play();
        System.out.println();
        bot2.play();
    }

}
