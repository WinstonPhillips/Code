import java.util.Scanner;

class Main {



  public static void geologyBlows(int geo) // worthless parameter lol
  {
    System.out.println("What is your favorite subject?");

    Scanner input = new Scanner(System.in);

    String acInput = input.nextLine();

    if (acInput.equals("Geology"))
    {
      System.out.println("You Dingus");
    }
    else 
    {
      System.out.println("There ya go");
    }

  }

  public static void main(String[] args) {
    System.out.println("Hello world!");

    geologyBlows(5);
  }
}