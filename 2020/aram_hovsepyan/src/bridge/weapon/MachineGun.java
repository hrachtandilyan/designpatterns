package bridge.weapon;

public class MachineGun extends Weapon {

    public MachineGun(int damage) {
        super(damage);
    }

    @Override
    public void shoot() {
        System.out.println("TRATATATATATATATAAAAA!");
    }

}
