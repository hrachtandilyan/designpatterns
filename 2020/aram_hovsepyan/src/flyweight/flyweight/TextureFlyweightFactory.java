package flyweight.flyweight;

import java.util.HashMap;
import java.util.Map;
import java.util.stream.IntStream;

public class TextureFlyweightFactory {

    private static TextureFlyweightFactory instance;

    private final Map<String, Texture> textures;

    private TextureFlyweightFactory() {
        textures = new HashMap<>();
        loadTextures();
    }

    public static TextureFlyweightFactory getInstance() {
        if (instance == null) {
            instance = new TextureFlyweightFactory();
        }
        return instance;
    }

    public Texture getTexture(String textureId) {
        return textures.get(textureId);
    }

    private void loadTextures() {
        IntStream.range(1, 11).forEach(i -> textures.put("bullet" + i, new Texture("assets/bullet" + i)));
        IntStream.range(1, 6).forEach(i -> textures.put("weapon" + i, new Texture("assets/weapon" + i)));
    }

}
