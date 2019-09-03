package pizza;

public class Hawaiian extends PizzaBuilder{
	
	// Builds a straight up Hawaiian Pizza 

	//Overriden method from parent class PizzaBuilder
	void BuildPizza(String crustSize, String crustType) // requires user input to set pizza
	{
			this.crust = new Crust(crustType, crustSize);
			this.pizza = new Pizza(this.crust);
			this.pizza = new Pineapple(this.pizza);
			this.pizza = new Ham(this.pizza);
	}
}