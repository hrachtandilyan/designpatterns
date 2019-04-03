package Abstract_Factory;
public class CrudoPizza extends Pizza{

	public CrudoPizza() {
		dough = "thin";
		souce = "barbeque";
		meat = true;
		slices = 6;
		
	}
	@Override
	public void prepare() {
		System.out.println("Crudo pizza is prepared!");
		
	}

	@Override
	public void bake() {
		System.out.println("Crudo pizza is baked!");
		
	}

	@Override
	public void cut() {
		System.out.println("Crudo pizza is cut into 6 slices!");
		
	}

	@Override
	public void serve() {
		System.out.println("Crudo pizza is served. Enjoy!");
		
	}
	
}