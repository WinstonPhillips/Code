package pizza;

public class Pepperoni extends DecoratedPizza{ // we can use this class to add on to a Decorated Pizza
	
	public Pepperoni(DecoratedPizza pizza)
	{
		super(pizza); // pizza to get pepperoni added to it
	}

	/*  Overides  */

	public double pizzaCost()
	{
		return getDecoratedPizza().pizzaCost()+.99;
	}
	public String toString()
	{
		return getDecoratedPizza().toString()+", Pepperoni";
	}
	public String getImage()
	{
		return getDecoratedPizza().getImage()+"P";
	}


}