package composite;

import java.util.ArrayList;
import java.util.List;

public class Pharaoh implements Egyptian {

    private static Pharaoh pharaoh;

    private final List<GovernmentOfficial> servants;

    private Pharaoh() {
        this.servants = new ArrayList<>();
    }

    public static Pharaoh getPharaoh() {
        if (pharaoh == null) {
            pharaoh = new Pharaoh();
        }
        return pharaoh;
    }


    @Override
    public void addServant(Egyptian egyptian) {
        if (egyptian instanceof GovernmentOfficial) {
            servants.add((GovernmentOfficial) egyptian);
            return;
        }
        System.out.println("Such a peasant can't serve Pharaoh!");
    }

    @Override
    public void killServant(Egyptian egyptian) {
        servants.remove(egyptian);
    }

    @Override
    public void work() {
        System.out.println("Pharaoh gives orders to goverment officials");
        for (GovernmentOfficial governmentOfficial : servants) {
            governmentOfficial.work();
        }
    }

    @Override
    public List<? extends Egyptian> getServants() {
        return servants;
    }

}
