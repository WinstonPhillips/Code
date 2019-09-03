package pizza;

public class DecoratedPizza{ // was abstract, now, for factory method, have instance variables 

	private double cost;
	private String description;
	private String imageString;

	private DecoratedPizza next_pizza_item; // shared by all toppings

	public DecoratedPizza getDecoratedPizza() // because our flippin Decorated Pizza is private
	{
		return next_pizza_item;
	}

	public DecoratedPizza()
	{
		this.next_pizza_item = null;
		this.cost = 0.0;
		this.description = "";
		this.imageString = "";
	}

	public DecoratedPizza(DecoratedPizza sentPizza)
	{
		this.next_pizza_item = sentPizza;
	}

	public double pizzaCost() 
	{
		return cost;
	}
	
	public String toString()
	{
		return description;
	}
	
	public String getImage()
	{
		return imageString;
	}
	public void addToImage(Crust crust)
	{
		imageString = crust.getSize() + imageString;
	}
	public void addTopping(PizzaTopping pt)
	{
		this.cost = this.cost + pt.topping_cost;
		this.description = this.description + ", " + pt.topping_string;
		this.imageString = this.imageString + pt.topping_letter;
	}
	public void addDiscount(double discount)
	{
		this.cost = this.cost*discount;
	}
	public void addFee(double fee)
	{
		this.cost = this.cost + fee;
	}
	


}