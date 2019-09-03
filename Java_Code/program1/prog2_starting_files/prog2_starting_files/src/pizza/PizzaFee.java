package pizza;

public class PizzaFee extends DecoratedPizza{
	public PizzaFee(DecoratedPizza pizza_component, String msg, double fee) 
	{
		pizza_component.addFee(2.50);
	}
}