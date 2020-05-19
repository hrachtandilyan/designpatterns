package factorymethod.calculator;

import factorymethod.util.State;

public class AggressivePlayCalculator implements PlayCalculator {

    @Override
    public void calculatePlay(State state) {
        System.out.println(String.format("Aggressive play for state:\n%s", state.toString()));
    }

}
