package factorymethod.models.players;

import factorymethod.models.balls.Ball;

public class BaseballPlayer implements Player {

    public static final int MAX_PLAYABLE_BALL_RADIUS = 10;

    @Override
    public void play(Ball ball) {
        if (ball.getRadius() > MAX_PLAYABLE_BALL_RADIUS) {
            System.out.println("Too big for my bat :(");
        } else {
            System.out.println("I'm bat-man");
        }
    }
}
