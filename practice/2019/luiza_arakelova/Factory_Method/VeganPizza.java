package Abstract_Factory;
public class VeganPizza extends Pizza{
	
	public VeganPizza() {
		dough = "thick";
		souce = "Espagnole";
		meat = false;
		slices = 12;
		
	}
	
	@Override
	public void prepare() {
		System.out.println("Vegan pizza is prepared!");
		
	}

	@Override
	public void bake() {
		System.out.println("Vegan pizza is baked!");
		
	}

	@Override
	public void cut() {
		System.out.println("Vegan pizza is cut into 12 slices!");
		
	}

	@Override
	public void serve() {
		System.out.println("Vegan pizza is served. Enjoy!");
		
	}
	
}