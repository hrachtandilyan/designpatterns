package factorymethod.bot;

import factorymethod.calculator.PlayCalculator;
import factorymethod.calculator.SmartPlayCalculator;
import factorymethod.util.State;

public class SmartBot extends Bot {

    public SmartBot(State state) {
        super(state);
    }

    @Override
    protected PlayCalculator createCalculator() {
        return new SmartPlayCalculator();
    }

}
