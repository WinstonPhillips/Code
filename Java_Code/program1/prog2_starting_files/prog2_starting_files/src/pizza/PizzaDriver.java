/* Written by Winston Phillips  T00212039 */
package pizza;
import util.*;
import java.text.DecimalFormat; // for decimal formatting the price
import java.io.File; // for file input
import java.util.Scanner;
import java.io.*;

public class PizzaDriver{

	private static int menu()
	{
		int userChoice;

		System.out.println("1. Meat Lover's\n 2. Veggie Lover's\n 3. Hawaiian\n 4. Build Your Own");

			do{
					userChoice = Keyboard.getKeyboard().readInt("Select from the above: ");

			}while(userChoice > 4 || userChoice < 1);

			return userChoice;
	}

	private static int menu(Scanner sc) // for using a file's lines
	{
		int userChoice;

		System.out.println("1. Meat Lover's\n 2. Veggie Lover's\n 3. Hawaiian\n 4. Build Your Own");
		System.out.print("\nSelect from the above: ");

			do{
					userChoice = Integer.parseInt(sc.next());

			}while(userChoice > 4 || userChoice < 1);

			return userChoice;
	}

	private static String requestSize(PizzaBuilder pizza_builder) // setting size
	{
		String userInput = "";

		do{

			userInput = Keyboard.getKeyboard().readString("Size (S/M/L): ");

		}while(!pizza_builder.setSize(userInput));

		return userInput.toUpperCase();

	}

	private static String requestSize(PizzaBuilder pizza_builder, Scanner sc) // for file input
	{
		String userInput = "";

		do{
			System.out.print("Size (S/M/L): \n\tChoice:");
			userInput = sc.next();
			System.out.println(userInput);


		}while(!pizza_builder.setSize(userInput));

		return userInput.toUpperCase();

	}

	private static String requestCrust(PizzaBuilder pizza_builder)
	{
		String userInput = "";


		do{

				userInput = Keyboard.getKeyboard().readString("What type of crust (thin/hand/pan): ");
		
		  }while(!pizza_builder.setCrust(userInput));

		  return userInput.toUpperCase();
	}

	private static String requestCrust(PizzaBuilder pizza_builder, Scanner sc)
	{
		String userInput = "";


		do{

				System.out.print("What type of crust (thin/hand/pan): ");
				userInput = sc.next();
				System.out.println(userInput);

		
		  }while(!pizza_builder.setCrust(userInput));

		  return userInput.toUpperCase();
	}

	// private DecoratedPizza requestToppings(DecoratedPizza pizza,PizzaToppingFactory ptf) // going to prompt user for toppings
	// {
	// 	String userString;

	// 	do{

	// 		userString = Keyboard.getKeyboard().readString("\n(P)epperoni,(O)nions,(G)reen Peppers\n(S)ausage,(M)ushrooms,(D)one \n\nChoice: ");

	// 		pizza = ptf.requestTopping(pizza, userString.charAt(0));

	// 	}while(userString.charAt(0) !='d' && userString.charAt(0) != 'D');

	// 	return pizza;

	// }

	private static void showOrder(DecoratedPizza pizza, String type, String size, PizzaToppingFactory ptf)
	{
		DecimalFormat cost = new DecimalFormat("#.##");

			System.out.println("\n\nYour order: \n");
			System.out.println("Original Cost: $" + cost.format(pizza.pizzaCost()+ptf.crust.getCost()));
			System.out.println("Toppings: " + pizza.toString());
			System.out.println("Size: "  + size);
			System.out.println("Type: "  + type);
	}

	


	public static void main (String[] args) throws Exception
	{
		int numPizzas = 0;
		int pizzaStyle;
		String size = "";
		String type = "";
		String userChoice = "";
		double totalCost = 0.0;
		DecimalFormat cost = new DecimalFormat("#.##");
		PizzaToppingFactory ptf = new PizzaToppingFactory();

		do{ // reading input from user or a file?
		pizzaStyle = Keyboard.getKeyboard().readInt("Do you wish to:\n1) Read input through user\n2) Read input through file\n\n\t Choice: ");
		}while(pizzaStyle < 1 || pizzaStyle > 2);

	if (pizzaStyle == 1)
	{
		userChoice = Keyboard.getKeyboard().readString("Do you wish to make a pizza? (y/n)");

		while(userChoice.charAt(0) == 'Y' || userChoice.charAt(0) == 'y')
		{
			DecoratedPizza pizza = null;

			PizzaBuilder pb = new PizzaBuilder(); // just for input validation

			pizzaStyle = menu();

			size = requestSize(pb); // input validation
			type = requestCrust(pb); // input validation
			pizza = ptf.MakePizza(size, type, pizza); // build pizza crust
			pizza = ptf.specialtyPizzas(pizzaStyle, pizza);

			totalCost = totalCost + pb.addDiscount(pizza.pizzaCost() + ptf.crust.getCost());

			totalCost = totalCost + pb.addFee(pizza);

			showOrder(pizza,type,size,ptf);
			
			//totalcost

			numPizzas++; // increment Pizzas

			userChoice = Keyboard.getKeyboard().readString("\nWould you like to make another pizza?(y/n): ");


		}
		

		System.out.println("---------------------------------------------------\n\nYou ordered " + numPizzas+ " pizza(s) for a total of $" + cost.format(totalCost) + " (Discounts & Fees Included)");

	}

	else if (pizzaStyle == 2)
	{
		String fileName = Keyboard.getKeyboard().readString("What is the file name: ");
		File file = new File(fileName);
		Scanner sc = new Scanner(file);


		do{ 
				
				System.out.println("Do you wish to make a pizza? (y/n)");
				userChoice = sc.next();
				System.out.println(userChoice);
				
		}while(userChoice.charAt(0) != 'y' && userChoice.charAt(0) != 'Y');


		do{
			DecoratedPizza pizza = null;

			PizzaBuilder pb = new PizzaBuilder(); // just for input validation

			pizzaStyle = menu(sc);
			System.out.println(pizzaStyle); // just show what we got


				
			size = requestSize(pb,sc); // input validation
			type = requestCrust(pb,sc); // input validation
			pizza = ptf.MakePizza(size, type, pizza); // build pizza crust, does not need validation
			pizza = ptf.specialtyPizzas(pizzaStyle, pizza, sc);

			totalCost = totalCost + pb.addDiscount((pizza.pizzaCost() + ptf.crust.getCost()), sc);

			totalCost = totalCost + pb.addFee(pizza, sc);

			showOrder(pizza,type,size,ptf);

			numPizzas++; // increment Pizzas

			System.out.print("\nWould you like to make another pizza?(y/n): ");
			userChoice = sc.next();
			System.out.print(userChoice);


		}while(userChoice.charAt(0) == 'Y' || userChoice.charAt(0) == 'y');
		

		System.out.println("\n\n---------------------------------------------------\n\nYou ordered " + numPizzas+ " pizza(s) for a total of $" + cost.format(totalCost) + " (Discounts & Fees Included)");

	}
}




}