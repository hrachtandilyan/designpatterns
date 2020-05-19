package abstractfactory.armour;

import java.util.ArrayList;
import java.util.List;

public class ShieldOfTheAbyss implements Armour {

    private final int baseDefense;
    private List<Integer> buffs;

    public ShieldOfTheAbyss(int baseDefense, List<Integer> buffs) {
        this.buffs = new ArrayList<>(buffs);
        this.baseDefense = baseDefense;
    }

    @Override
    public int getDefense() {
        return baseDefense + calculateBuff();
    }

    public void setBuffs(List<Integer> buffs) {
        this.buffs = buffs;
    }

    private int calculateBuff() {
        return buffs.stream().reduce(Integer::sum).orElse(0);
    }

}
