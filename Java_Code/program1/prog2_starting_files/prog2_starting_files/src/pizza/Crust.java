package pizza;

public class Crust{

	private CrustEnum myCrust; // containes CrustType enum, CrustSize enum, and can getCost() to return total cost

	public Crust(String type, String size)
	{
		this.myCrust = new CrustEnum(type,size);
	}

	public double getCost()
	{
		return this.myCrust.getCost(); // cost of Crust type and size
	}

	public String getCrust()
	{
		return myCrust.getCrust(); // roots all the way back to our enum
	}

	public String getSize()
	{
		return myCrust.getSize();	// roots all the way back to our enum
	}


}
