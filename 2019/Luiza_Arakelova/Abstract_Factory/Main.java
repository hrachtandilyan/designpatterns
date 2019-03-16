package Abstract_Factory;

public class Main {
	public static void main(String [] args) {
		
		Pizza pizza = PizzaFactory.makePizza("Cheesy");
		System.out.println("Yuhoo! Your "+ pizza.dough+" dough, " + pizza.slices+ " slices," + " with "+pizza.souce + " souce pizza " +"has been eaten!\n");
		
		Pizza pizza1 = PizzaFactory.makePizza("Crudo");
		System.out.println("Yuhoo! Your "+ pizza1.dough+" dough, " + pizza1.slices+ " slices," + " with "+pizza1.souce + " souce pizza " +"has been eaten!\n");
		
		Pizza pizza2 = PizzaFactory.makePizza("Vegan");
		System.out.println("Yuhoo! Your "+ pizza2.dough+" dough, " + pizza2.slices+ " slices," + " with "+pizza2.souce + " souce pizza " +"has been eaten!\n");
	}
	
}