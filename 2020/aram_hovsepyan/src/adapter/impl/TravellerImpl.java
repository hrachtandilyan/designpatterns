package adapter.impl;

import adapter.api.Traveller;

public class TravellerImpl implements Traveller {

    private int speed;
    private int position;

    public TravellerImpl(int speed, int position) {
        this.speed = speed;
        this.position = position;
    }

    @Override
    public void moveTo(int position) {
        this.position += Math.min(speed, Math.abs(this.position - position)) * Math.signum(position - this.position);
    }

    @Override
    public boolean isInPosition(int position) {
        return this.position == position;
    }

}
