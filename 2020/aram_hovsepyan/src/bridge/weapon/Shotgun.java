package bridge.weapon;

public class Shotgun extends Weapon {

    public Shotgun(int damage) {
        super(damage);
    }

    @Override
    public void shoot() {
        System.out.println("BAM! *shotgun reloading sound*");
    }

}
