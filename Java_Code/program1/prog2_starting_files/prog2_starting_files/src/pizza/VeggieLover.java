package pizza;

public class VeggieLover extends PizzaBuilder{
	
	// Builds a straight up Veggie Lover's pizza

	//Overriden method from parent class PizzaBuilder
	void BuildPizza(String crustSize, String crustType) // requires user input to set pizza
	{
			this.crust = new Crust(crustType, crustSize);
			this.pizza = new Pizza(this.crust);
			this.pizza = new Pineapple(this.pizza);
			this.pizza = new Onions(this.pizza);
			this.pizza = new GreenPeppers(this.pizza);
			this.pizza = new Mushrooms(this.pizza);
	}
}