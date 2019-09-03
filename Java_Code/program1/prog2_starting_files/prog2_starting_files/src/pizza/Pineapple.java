package pizza;

public class Pineapple extends DecoratedPizza{

	public Pineapple(DecoratedPizza pizza)
	{
		super(pizza); // pizza to get pepperoni added to it
	}

	/*  Overides  */

	public double pizzaCost()
	{
		return getDecoratedPizza().pizzaCost()+.89;
	}
	public String toString()
	{
		return getDecoratedPizza().toString()+", Pineapple";
	}
	public String getImage()
	{
		return getDecoratedPizza().getImage()+"A";
	}
}