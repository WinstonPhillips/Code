package pizza;

public class Pizza extends DecoratedPizza{ // represents just pizza with crust

	Crust myCrust; // crust that will be sent

	public Pizza(Crust sentCrust)
	{
		super(); // sets next_pizza_item from parent class to null
		this.myCrust = sentCrust;
	}

	public double pizzaCost() 
	{
		return myCrust.getCost();
	}
	
	public String toString()
	{
		return myCrust.getCrust();
	}
	
	public String getImage()
	{
		return myCrust.getSize();
	}
}