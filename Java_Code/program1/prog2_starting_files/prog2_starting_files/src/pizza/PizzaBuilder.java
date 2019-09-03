package pizza;

import java.util.Scanner; // for file input
import util.*;

public class PizzaBuilder{ // handles all input validation

	DecoratedPizza pizza;
	Crust crust;

	public PizzaBuilder() // constructor that creates the default pizza 
	{
		this.crust = new Crust("THIN", "S");
		this.pizza = new Pizza(this.crust); // we now have a small, thin crust pizza
	}

	void BuildPizza(String crustSize, String crustType) // requires user input to set pizza
	{
			this.crust = new Crust(crustType, crustSize.toUpperCase());
			this.pizza = new Pizza(this.crust);
	}

	public boolean setSize(String sizeChar) 
	{
		char try_size = sizeChar.charAt(0);

		if (try_size != 's' && try_size != 'S' && try_size != 'm' && try_size != 'M' && try_size != 'l' && try_size != 'L')
		{
			return false;
		}

		else 
		{
			return true;
		}
	}

	public boolean setCrust(String try_crust) 
	{
		if(!try_crust.equals("thin") && !try_crust.equals("THIN") && !try_crust.equals("hand") && !try_crust.equals("HAND") && !try_crust.equals("pan") && !try_crust.equals("PAN"))
		{
			return false;
		}
		else
		{
			return true;
		}
	}

    public void addTopping(char topping_char) // doesn't return anything, so we have to add topping here
    {
    	

    	

    		if(topping_char == 'P' || topping_char == 'p')
    	 	{
    	 		this.pizza = new Pepperoni(this.pizza);
    	 	}
    	 	else if(topping_char == 'S' || topping_char == 's')
    	 	{
    	 		this.pizza = new Sausage(this.pizza);
    	 	}
    	 	else if(topping_char == 'G' || topping_char == 'g')
    	 	{
    	 		this.pizza = new GreenPeppers(this.pizza);
    	 	}
    	 	else if(topping_char == 'M' || topping_char == 'm')
    	 	{
    			this.pizza = new Mushrooms(this.pizza);
    	 	}
    	 	else if(topping_char == 'O' || topping_char == 'o')
    	 	{
    			this.pizza = new Onions(this.pizza);
    	 	}
    	 	else
    		{
    			//ignored
    	 	}

    	

    }

    public DecoratedPizza pizzaDone()
    {
    	return this.pizza;
    }

    public String returnCrust()
    {
    	return this.crust.getCrust();
    }

    public String returnSize()
    {
    	return this.crust.getSize();
    }

    public double addDiscount(double cost)
    {
        String answer;
        do{

        answer = Keyboard.getKeyboard().readString("Are you a senior citizen?(y/n): ");

          }while(answer.charAt(0) != 'Y' && answer.charAt(0) != 'y' && answer.charAt(0) != 'n' && answer.charAt(0) != 'N');

        if (answer.charAt(0) == 'y' || answer.charAt(0) == 'Y')
        {
           cost = cost * .90;
        }
        
        return cost;
    }

    public double addDiscount(double cost, Scanner sc) // for file input
    {
        String answer;
        do{

        System.out.print("Are you a senior citizen?(y/n): ");
        answer = sc.next();
        System.out.println(answer);

          }while(answer.charAt(0) != 'Y' && answer.charAt(0) != 'y' && answer.charAt(0) != 'n' && answer.charAt(0) != 'N');

        if (answer.charAt(0) == 'y' || answer.charAt(0) == 'Y')
        {
           cost = cost * .90;
        }
        
        return cost;
    }

    public double addFee(DecoratedPizza pizza)
    {
        String answer;
        do{

        answer = Keyboard.getKeyboard().readString("Do you need the Pizza delivered?(y/n): ");

          }while(answer.charAt(0) != 'Y' && answer.charAt(0) != 'y' && answer.charAt(0) != 'n' && answer.charAt(0) != 'N');

        if(answer.charAt(0) == 'y' || answer.charAt(0) == 'Y')
        {
           return 2.50;
        }
       else
       {
        return 0.0;
       }

    }

    public double addFee(DecoratedPizza pizza, Scanner sc)
    {
        String answer;
        do{

            System.out.print("Do you need the Pizza delivered?(y/n): ");
            answer = sc.next(); 
            System.out.println(answer);

          }while(answer.charAt(0) != 'Y' && answer.charAt(0) != 'y' && answer.charAt(0) != 'n' && answer.charAt(0) != 'N');

        if(answer.charAt(0) == 'y' || answer.charAt(0) == 'Y')
        {
           return 2.50;
        }
       else
       {
        return 0.0;
       }

    }


}