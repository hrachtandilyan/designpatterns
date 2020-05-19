package adapter.impl;

import adapter.api.Teleporter;

public class TeleporterImpl implements Teleporter {

    private int position;

    public TeleporterImpl(int position) {
        this.position = position;
    }

    @Override
    public void teleportTo(int position) {
        this.position = position;
    }

}
