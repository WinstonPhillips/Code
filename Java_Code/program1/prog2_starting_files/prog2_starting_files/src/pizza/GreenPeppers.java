package pizza;

public class GreenPeppers extends DecoratedPizza{

	public GreenPeppers(DecoratedPizza pizza)
	{
		super(pizza); // pizza to get pepperoni added to it
	}

	/*  Overides  */

	public double pizzaCost()
	{
		return getDecoratedPizza().pizzaCost()+.69;
	}
	public String toString()
	{
		return getDecoratedPizza().toString()+", Green Peppers";
	}
	public String getImage()
	{
		return getDecoratedPizza().getImage()+"G";
	}
}