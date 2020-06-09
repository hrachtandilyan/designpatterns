package flyweight.flyweight;

import java.io.FileInputStream;
import java.io.IOException;

public class Texture {

    private final byte[] content;

    public Texture(String path) {
        try {
            this.content = new FileInputStream(path).readAllBytes();
        } catch (IOException e) {
            throw new IllegalArgumentException("Something wrong with the file", e);
        }
    }

    public void draw(float x, float y, float rotation, float originX, float originY, float scale) {
        System.out.println("Scam, doesn't draw");
    }

}
