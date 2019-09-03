package pizza;

public class Onions extends DecoratedPizza{

	public Onions(DecoratedPizza pizza)
	{
		super(pizza); // pizza to get pepperoni added to it
	}

	/*  Overides  */

	public double pizzaCost()
	{
		return getDecoratedPizza().pizzaCost()+.79;
	}
	public String toString()
	{
		return getDecoratedPizza().toString()+", Onions";
	}
	public String getImage()
	{
		return getDecoratedPizza().getImage()+"O";
	}
}