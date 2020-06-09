package flyweight.elements;

import flyweight.flyweight.Texture;

public class Weapon {

    private Texture texture;
    public float x;
    public float y;
    public boolean left;

    public Weapon(Texture texture) {
        this.texture = texture;
    }

}
