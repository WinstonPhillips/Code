package pizza;

public class CrustEnum{ // basically throwns our two enums together in one enum class named CrustEnum

	/*Enums defined above our crust class */
	public enum CrustSize{

		S(5.99), M(7.99), L(9.99);  // possible values of CrustSize to be set

		private double price; // price attribute for pizza size

		private CrustSize(double price) // contructor for the size of crust, sets price of crust
	       {
	           this.price = price;
	       }

	     public double getCost() // return cost of crust
	     {
	            return this.price;
	     }

	     public String getSize()
	     {
	     	return toString(); // one of the static values of our enum
	     }

	}

	public enum CrustType{

		THIN(0.00), HAND(0.50), PAN(1.00);

		private double price;  

		private CrustType(double price) // contructor for the size of crust
	       {
	           this.price = price;
	       }

	     public double getCost()
	     {
	        return this.price;
	     }

	     public String getCrust()
	     {
	     	return toString(); // one of the static values of our enum
	     }

	}

		private CrustSize size; // in our Crust Size range with crustSize attributes (enum)
		private CrustType type;	// in our Crust Size range with crustType attributes (enum)

		public CrustEnum(String type, String size)  //constructor for crust
		{
			this.type = CrustType.valueOf(type); // example. CrustSize.S(5.99);
			this.size = CrustSize.valueOf(size);
		}

		public double getCost() // return cost of crust type and size, really kind of the point of the class
		{
			return (type.getCost() + size.getCost());
		}

		  public String getCrust()
	     {
	     	return type.getCrust();
	     }

	     public String getSize()
	     {
	     	return size.getSize();
	     }



}