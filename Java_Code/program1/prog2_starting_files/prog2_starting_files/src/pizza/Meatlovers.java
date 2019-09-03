package pizza;


public class Meatlovers extends PizzaBuilder{
	
	// Builds a straight up Meatlover's Pizza 

	//Overriden method from parent class PizzaBuilder
	void BuildPizza(String crustSize, String crustType) // requires user input to set pizza
	{
			this.crust = new Crust(crustType, crustSize);
			this.pizza = new Pizza(this.crust);
			this.pizza = new Sausage(this.pizza);
			this.pizza = new Pepperoni(this.pizza);
			this.pizza = new Ham(this.pizza);
	}
}