package composite;

import java.util.List;

public class Slave implements Egyptian {

    @Override
    public void addServant(Egyptian egyptian) {
        throw new UnsupportedOperationException("Slaves don't have servants!");
    }

    @Override
    public void killServant(Egyptian egyptian) {
        throw new UnsupportedOperationException("Slaves don't have servants!");
    }

    @Override
    public void work() {
        System.out.println("A slave does his slave work");
    }

    @Override
    public List<? extends Egyptian> getServants() {
        throw new UnsupportedOperationException("Slaves don't have servants!");
    }

}
