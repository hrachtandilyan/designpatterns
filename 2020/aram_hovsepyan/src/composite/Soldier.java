package composite;

import java.util.ArrayList;
import java.util.List;

public class Soldier implements Egyptian {

    private final List<Slave> slaves;

    public Soldier() {
        this.slaves = new ArrayList<>();
    }

    @Override
    public void addServant(Egyptian egyptian) {
        if (egyptian instanceof Slave) {
            slaves.add((Slave) egyptian);
            return;
        }
        System.out.println("Only slaves can serve a soldier!");
    }

    @Override
    public void killServant(Egyptian egyptian) {
        slaves.remove(egyptian);
    }

    @Override
    public void work() {
        System.out.println("Soldier makes his slaves work and defends the Pharaoh");
        for (Slave slave : slaves) {
            slave.work();
        }
    }

    @Override
    public List<? extends Egyptian> getServants() {
        return slaves;
    }

}
