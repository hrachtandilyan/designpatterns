package composite;

import java.util.List;

public interface Egyptian {

    void addServant(Egyptian egyptian);

    void killServant(Egyptian egyptian);

    void work();

    List<? extends Egyptian> getServants();

}
