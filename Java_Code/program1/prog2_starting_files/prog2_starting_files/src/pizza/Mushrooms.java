package pizza;

public class Mushrooms extends DecoratedPizza{

	public Mushrooms(DecoratedPizza pizza)
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
		return getDecoratedPizza().toString()+", Mushrooms";
	}
	public String getImage()
	{
		return getDecoratedPizza().getImage()+"M";
	}
}