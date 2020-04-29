public  class PlaystationFactory implements GameConsoleAbstractFactory {
        private String ram;
        private String hdd;
        private String cpu;

	public PlaystationFactory(String ram, String hdd, String cpu){
            this.ram=ram;
            this.hdd=hdd;
            this.cpu=cpu;
    }
    @Override
    public GameConsole createConsole() {
        return new Playstation(ram,hdd,cpu);
    }
}
