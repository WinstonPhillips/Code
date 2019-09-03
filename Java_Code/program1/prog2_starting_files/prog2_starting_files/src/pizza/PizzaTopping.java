package pizza;

public class PizzaTopping{

    DecoratedPizza pizza_component;
    String topping_string;
	String topping_letter;
	double topping_cost;

	 public PizzaTopping(DecoratedPizza pizza_component, String topping_string, String topping_letter, double topping_cost) 
	 {
	 		this.pizza_component = pizza_component;

	 		this.topping_string = topping_string;
	 		this.topping_letter = topping_letter;
	 		this.topping_cost = topping_cost;
	 }




}