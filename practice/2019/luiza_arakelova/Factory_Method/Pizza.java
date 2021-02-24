package Abstract_Factory;

public abstract class Pizza {
	
	String dough;
	String souce;
	boolean meat;
	int slices;
	

	public abstract void prepare();
	public abstract void bake();
	public abstract void cut();
	public abstract void serve();
	
	
}