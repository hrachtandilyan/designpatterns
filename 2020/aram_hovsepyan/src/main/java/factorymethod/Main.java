package factorymethod;

import factorymethod.models.balls.Ball;
import factorymethod.models.balls.BaseballBall;
import factorymethod.models.players.BaseballPlayer;
import factorymethod.models.players.Player;

public class Main {

    public static void main(String[] args) {
        buildPlayer().play(buildBall());
    }

    private static Player buildPlayer() {
        return new BaseballPlayer();
    }

    private static Ball buildBall() {
        return new BaseballBall();
    }

}
