package Abstract_Factory;
public class CheesyPizza extends Pizza{

	public CheesyPizza() {
		dough = "thick";
		souce = "creamy";
		meat = false;
		slices = 4;
		
	}
	@Override
	public void prepare() {
		System.out.println("Cheesy pizza is prepared!");
		
	}

	@Override
	public void bake() {
		System.out.println("Cheesy pizza is baked!");
		
	}

	@Override
	public void cut() {
		System.out.println("Cheesy pizza is cut into 4 slices!");
		
	}

	@Override
	public void serve() {
		System.out.println("Cheesy pizza is served. Enjoy!");
		
	}
	
}