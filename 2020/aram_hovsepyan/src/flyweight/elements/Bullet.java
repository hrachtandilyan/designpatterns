package flyweight.elements;

import flyweight.flyweight.Texture;

public class Bullet {

    private Texture texture;
    public float x;
    public float y;
    public float rotation;

    public Bullet(Texture texture) {
        this.texture = texture;
    }

}
