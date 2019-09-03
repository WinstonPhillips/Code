package pizza;

import util.*;
import java.util.Scanner; // for file input

public class PizzaToppingFactory{

	PizzaTopping pt;
	Crust crust;

	public PizzaToppingFactory()
	{
		//void
	}
	public DecoratedPizza MakePizza(String crustSize, String crustType,DecoratedPizza pizza) 
	{
			this.crust = new Crust(crustType.toUpperCase(), crustSize.toUpperCase());
			pizza = new DecoratedPizza();
			pizza.addToImage(this.crust);
			return pizza;
			
	}


	public DecoratedPizza specialtyPizzas(int x, DecoratedPizza sentPizza) // following factory method
	{
		if (x == 1)
		{
			sentPizza = MeatLovers(sentPizza);
		}
		else if(x == 2)
		{
			sentPizza = VeggyLovers(sentPizza);
		}
		else if (x == 3)
		{
			sentPizza = Hawaiian(sentPizza);
		}
		else
		{
			return requestTopping(sentPizza);
		}

		return sentPizza;
	}


	public DecoratedPizza specialtyPizzas(int x, DecoratedPizza sentPizza, Scanner sc) // ffactoy method for file input
	{
		if (x == 1)
		{
			sentPizza = MeatLovers(sentPizza);
		}
		else if(x == 2)
		{
			sentPizza = VeggyLovers(sentPizza);
		}
		else if (x == 3)
		{
			sentPizza = Hawaiian(sentPizza);
		}
		else
		{
			return requestTopping(sentPizza, sc);
		}

		return sentPizza;
	}


	public DecoratedPizza requestTopping(DecoratedPizza sentPizza)
	{
		String userString = "";
		char topping_char; 
		do{

			userString = Keyboard.getKeyboard().readString("\n(P)epperoni,(O)nions,(G)reen Peppers\n(S)ausage,(M)ushrooms,(D)one \n\nChoice: ");

			topping_char = userString.charAt(0);

			if(topping_char == 'P' || topping_char == 'p')
    		{
    			sentPizza = addPepperoni(sentPizza);
    		}
    		else if(topping_char == 'S' || topping_char == 's')
    		{
    			sentPizza = addSausage(sentPizza);
    		}
    		else if(topping_char == 'G' || topping_char == 'g')
    		{
    			sentPizza = addGreenPeppers(sentPizza);
    		}
    		else if(topping_char == 'M' || topping_char == 'm')
    		{
    			sentPizza = addMushrooms(sentPizza);
    		}
    		else if(topping_char == 'O' || topping_char == 'o')
    		{
    			sentPizza = addOnions(sentPizza);
    		}
    		else
    		{
    			//ignored
    		}


		}while(userString.charAt(0) !='d' && userString.charAt(0) != 'D');
	

    		return sentPizza;
	}

	public DecoratedPizza requestTopping(DecoratedPizza sentPizza, Scanner sc) // for file input
	{
		String userString = "";
		char topping_char; 
		do{

			System.out.print("\n(P)epperoni,(O)nions,(G)reen Peppers\n(S)ausage,(M)ushrooms,(D)one \n\nChoice: ");

			userString = sc.next();

			topping_char = userString.charAt(0);

			System.out.println(topping_char);

			if(topping_char == 'P' || topping_char == 'p')
    		{
    			sentPizza = addPepperoni(sentPizza);
    		}
    		else if(topping_char == 'S' || topping_char == 's')
    		{
    			sentPizza = addSausage(sentPizza);
    		}
    		else if(topping_char == 'G' || topping_char == 'g')
    		{
    			sentPizza = addGreenPeppers(sentPizza);
    		}
    		else if(topping_char == 'M' || topping_char == 'm')
    		{
    			sentPizza = addMushrooms(sentPizza);
    		}
    		else if(topping_char == 'O' || topping_char == 'o')
    		{
    			sentPizza = addOnions(sentPizza);
    		}
    		else
    		{
    			//ignored
    		}


		}while(userString.charAt(0) !='d' && userString.charAt(0) != 'D');
	

    		return sentPizza;
	}


	 public DecoratedPizza addPepperoni(DecoratedPizza dec_pizza)
	 {
	 	pt = new PizzaTopping(dec_pizza,"Pepperoni","P",.99);
	 	dec_pizza.addTopping(pt);
	 	return dec_pizza;

	 }

	 public DecoratedPizza addSausage(DecoratedPizza dec_pizza)
	 {
	 	pt = new PizzaTopping(dec_pizza,"Sausage","S",.99);
	 	dec_pizza.addTopping(pt);
	 	return dec_pizza;
	 	
	 }
	 public DecoratedPizza addOnions(DecoratedPizza dec_pizza)
	 {
	 	pt = new PizzaTopping(dec_pizza,"Onions","O",.79);
	 	dec_pizza.addTopping(pt);
	 	return dec_pizza;
	 	
	 }

	 public DecoratedPizza addGreenPeppers(DecoratedPizza dec_pizza)
	 {
	 	pt = new PizzaTopping(dec_pizza,"Green Peppers","G",.69);
	 	dec_pizza.addTopping(pt);
	 	return dec_pizza;
	 	
	 }

	 public DecoratedPizza addMushrooms(DecoratedPizza dec_pizza)
	 {
	 	pt = new PizzaTopping(dec_pizza,"Mushrooms","M",.79);
	 	dec_pizza.addTopping(pt);
	 	return dec_pizza;
	 	
	 }

	 public DecoratedPizza addHam(DecoratedPizza dec_pizza)
	 {
	 	pt = new PizzaTopping(dec_pizza,"Ham","H",.89);
	 	dec_pizza.addTopping(pt);
	 	return dec_pizza;
	 	
	 }

	 public DecoratedPizza addPineapple(DecoratedPizza dec_pizza)
	 {
	 	pt = new PizzaTopping(dec_pizza,"Pineapple","A",.89);
	 	dec_pizza.addTopping(pt);
	 	return dec_pizza;
	 
	 }

	 public DecoratedPizza MeatLovers(DecoratedPizza dec_pizza)
	 {
	 	pt = new PizzaTopping(dec_pizza,"Pepperoni","P",.99);
	 	dec_pizza.addTopping(pt);
	 	pt = new PizzaTopping(dec_pizza,"Sausage","S",.99);
	 	dec_pizza.addTopping(pt);
	 	pt = new PizzaTopping(dec_pizza,"Ham","H",.89);
	 	dec_pizza.addTopping(pt);

	 	return dec_pizza;
	 }

	  public DecoratedPizza VeggyLovers(DecoratedPizza dec_pizza)
	 {
	 	pt = new PizzaTopping(dec_pizza,"Onions","O",.79);
	 	dec_pizza.addTopping(pt);
	 	pt = new PizzaTopping(dec_pizza,"Green Peppers","G",.69);
	 	dec_pizza.addTopping(pt);
	 	pt = new PizzaTopping(dec_pizza,"Mushrooms","M",.79);
	 	dec_pizza.addTopping(pt);

	 	return dec_pizza;
	 }

	  public DecoratedPizza Hawaiian(DecoratedPizza dec_pizza)
	 {
	 	pt = new PizzaTopping(dec_pizza,"Ham","H",.89);
	 	dec_pizza.addTopping(pt);
	 	pt = new PizzaTopping(dec_pizza,"Pineapple","A",.89);
	 	dec_pizza.addTopping(pt);

	 	return dec_pizza;
	 }



}