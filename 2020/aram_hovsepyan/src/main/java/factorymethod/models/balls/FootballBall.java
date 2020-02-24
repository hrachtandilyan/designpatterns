package factorymethod.models.balls;

public class FootballBall implements Ball {

    public static final float RADIUS = 20;

    @Override
    public float getRadius() {
        return RADIUS;
    }

}
