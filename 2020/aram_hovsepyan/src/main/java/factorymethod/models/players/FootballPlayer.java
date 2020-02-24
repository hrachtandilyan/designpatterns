package factorymethod.models.players;

import factorymethod.models.balls.Ball;

public class FootballPlayer implements Player {

    public static final int MIN_PLAYABLE_BALL_RADIUS = 15;

    @Override
    public void play(Ball ball) {
        if (ball.getRadius() < MIN_PLAYABLE_BALL_RADIUS) {
            System.out.println("To small, can't play football with this :(");
        } else {
            System.out.println("Nice ball, I'll play :)");
        }
    }

}
