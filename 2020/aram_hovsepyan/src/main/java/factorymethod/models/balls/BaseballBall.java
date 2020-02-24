package factorymethod.models.balls;

public class BaseballBall implements Ball {

    public static final float RADIUS = 4;

    @Override
    public float getRadius() {
        return RADIUS;
    }

}
