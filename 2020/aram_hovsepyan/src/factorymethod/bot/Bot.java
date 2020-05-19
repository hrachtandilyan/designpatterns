package factorymethod.bot;

import factorymethod.calculator.PlayCalculator;
import factorymethod.util.State;

public abstract class Bot {

    private final State state;
    private final PlayCalculator playCalculator;

    protected Bot(State state) {
        this.state = state;
        this.playCalculator = createCalculator();
    }

    public void play() {
        playCalculator.calculatePlay(state);
    }

    protected abstract PlayCalculator createCalculator();

}
