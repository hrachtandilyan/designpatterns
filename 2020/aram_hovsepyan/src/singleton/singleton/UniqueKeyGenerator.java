package singleton.singleton;

import java.util.HashSet;
import java.util.Random;
import java.util.Set;

public class UniqueKeyGenerator {

    private static final int KEY_LENGTH = 8;

    private static UniqueKeyGenerator instance;

    private final Random random;
    private final Set<String> generatedKeys;
    private final String alphaNumericString;

    private UniqueKeyGenerator() {
        this.random = new Random();
        this.generatedKeys = new HashSet<>();
        this.alphaNumericString = "abcdefghijklmnopqrstuvxyz" +
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ" +
                "0123456789";
    }

    public static UniqueKeyGenerator getInstance() {
        if (instance == null) {
            instance = new UniqueKeyGenerator();
        }
        return instance;
    }

    public String generateKey() {
        String result;
        do {
            result = generateRandom();
        } while (generatedKeys.contains(result));
        generatedKeys.add(result);
        return result;
    }

    private String generateRandom() {
        StringBuilder stringBuilder = new StringBuilder(KEY_LENGTH);
        for (int i = 0; i < KEY_LENGTH; i++) {
            stringBuilder.append(alphaNumericString.charAt(random.nextInt(alphaNumericString.length())));
        }
        return stringBuilder.toString();
    }

}
