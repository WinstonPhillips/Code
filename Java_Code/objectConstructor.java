import java.util.Scanner;

class Student {
  // variables 
    String tNumber;
    String Name;

    // constructor 

    Student(String num, String dankName)
    {
      tNumber = num;
      Name = dankName;
    }

    void displayInfo()
    {
      System.out.println("\nStudent: " + Name);
      System.out.println("\nTNumber: T" + tNumber);
    }
}

class Main {
  public static void main(String[] args) {
    Scanner inputName = new Scanner(System.in);
    Scanner inputTNum = new Scanner(System.in);

    System.out.println("Welcome to Student creator!\n");

    System.out.println("Please enter the name of the student: ");
      String dankName = inputName.nextLine();
    
    System.out.println("Please enter " + dankName + "'s Tnumber: ");

      String dankNum = inputTNum.nextLine();

     // could create this variable, but we should just send the method to the Student constructor int numTosend = Integer.parseInt(dankNum);

    Student myStudent = new Student(dankNum, dankName);

    myStudent.displayInfo();

}

}