package abstractfactory.weapon;

import java.util.ArrayList;
import java.util.List;

public class SwordOfTheAbyss implements Weapon {

    private final int baseDamage;
    private List<Integer> buffs;

    public SwordOfTheAbyss(int baseDamage, List<Integer> buffs) {
        this.buffs = new ArrayList<>(buffs);
        this.baseDamage = baseDamage;
    }

    @Override
    public int getDamage() {
        return baseDamage + calculateBuff();
    }

    public void setBuffs(List<Integer> buffs) {
        this.buffs = buffs;
    }

    private int calculateBuff() {
        return buffs.stream().reduce(Integer::sum).orElse(0);
    }

}
