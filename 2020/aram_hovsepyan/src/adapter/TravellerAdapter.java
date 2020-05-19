package adapter;

import adapter.api.Teleporter;
import adapter.impl.TravellerImpl;

public class TravellerAdapter implements Teleporter {

    private final TravellerImpl traveller;

    public TravellerAdapter(TravellerImpl traveller) {
        this.traveller = traveller;
    }

    @Override
    public void teleportTo(int position) {
        while (!traveller.isInPosition(position)) {
            traveller.moveTo(position);
        }
    }

}
