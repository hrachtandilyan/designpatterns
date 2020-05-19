package factorymethod.bot;

import factorymethod.calculator.AggressivePlayCalculator;
import factorymethod.calculator.PlayCalculator;
import factorymethod.util.State;

public class AggressiveBot extends Bot {

    public AggressiveBot(State state) {
        super(state);
    }

    @Override
    protected PlayCalculator createCalculator() {
        return new AggressivePlayCalculator();
    }

}
