package Abstract_Factory;

public class PizzaFactory  {
	
	public static Pizza makePizza(String name) {
		Pizza pizza = null;
		
		if (name == "Cheesy") {
			 pizza = new CheesyPizza();
			}
		if (name == "Vegan") {
			pizza = new VeganPizza();
		}
		if (name == "Crudo") {
			pizza = new CrudoPizza();
		}
		
		pizza.prepare();
		pizza.bake();
		pizza.cut();
		pizza.serve();
		
		return pizza;
	}

	
	
		
	
	
}