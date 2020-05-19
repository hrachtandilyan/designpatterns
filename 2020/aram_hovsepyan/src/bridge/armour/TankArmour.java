package bridge.armour;

public class TankArmour extends Armour {

    public TankArmour(int defence) {
        super(defence);
    }

    @Override
    protected void effectsOnHit(int damage) {
        defence += damage / 15;
    }

}
