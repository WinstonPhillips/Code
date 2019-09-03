package pizza;

public class Sausage extends DecoratedPizza{

	public Sausage(DecoratedPizza pizza)
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
		return getDecoratedPizza().toString()+", Sausage";
	}
	public String getImage()
	{
		return getDecoratedPizza().getImage()+"S";
	}
}