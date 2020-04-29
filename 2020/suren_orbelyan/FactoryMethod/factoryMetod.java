public class factoryMetod {
    public static void main(String[] args) {
        PhoneFactory phoneFactory = new PhoneFactory();
        Phone phone1 = PhoneFactory.getPhone("SAMSUNG");
        phone1.camera();
        Phone phone2 = PhoneFactory.getPhone("IPHONE");
        phone2.camera();
    }
}
