public class PhoneFactory {
    public static Phone getPhone(String phoneType) {
        if (phoneType == null) {
            return null;
        }
        if (phoneType.equalsIgnoreCase("SAMSUNG")) {
            return new Samsung();

        } else if (phoneType.equalsIgnoreCase("IPHONE")) {
            return new Iphone();
        }
        return null;
    }
}
