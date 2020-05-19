package abstractfactory.armour;

public class DarknessGauntlets implements Armour {

    private int defense;

    public DarknessGauntlets(int defense) {
        this.defense = defense;
    }

    @Override
    public int getDefense() {
        return defense;
    }

    public void setDefense(int defense) {
        this.defense = defense;
    }

}
