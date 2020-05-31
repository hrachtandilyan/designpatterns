package composite;

import java.util.ArrayList;
import java.util.List;

public class GovernmentOfficial implements Egyptian {

    private final List<Soldier> soldiers;

    public GovernmentOfficial() {
        this.soldiers = new ArrayList<>();
    }

    @Override
    public void addServant(Egyptian egyptian) {
        if (egyptian instanceof Soldier) {
            soldiers.add((Soldier) egyptian);
            return;
        }
        System.out.println("Only soldiers can serve a goverment official!");
    }

    @Override
    public void killServant(Egyptian egyptian) {
        soldiers.remove(egyptian);
    }

    @Override
    public void work() {
        System.out.println("Goverment official is searching a place for the new pyramid");
        for (Soldier soldier : soldiers) {
            soldier.work();
        }
    }

    @Override
    public List<? extends Egyptian> getServants() {
        return soldiers;
    }

}
