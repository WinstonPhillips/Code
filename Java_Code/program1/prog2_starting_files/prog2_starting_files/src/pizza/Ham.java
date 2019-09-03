package pizza;

public class Ham extends DecoratedPizza{

	public Ham(DecoratedPizza pizza)
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
		return getDecoratedPizza().toString()+", Ham";
	}
	public String getImage()
	{
		return getDecoratedPizza().getImage()+"H";
	}
}