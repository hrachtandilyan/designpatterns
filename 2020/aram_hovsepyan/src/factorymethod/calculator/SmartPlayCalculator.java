package factorymethod.calculator;

import factorymethod.util.State;

public class SmartPlayCalculator implements PlayCalculator {

    @Override
    public void calculatePlay(State state) {
        System.out.println(String.format("Smart play for state:\n%s", state.toString()));
    }

}
