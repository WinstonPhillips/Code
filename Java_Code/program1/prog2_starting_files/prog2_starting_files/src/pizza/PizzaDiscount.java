package pizza;

public class PizzaDiscount extends DecoratedPizza{

	public PizzaDiscount(DecoratedPizza pizza_component, String msg, double discount)
	{
		pizza_component.addDiscount(discount);
	}
}