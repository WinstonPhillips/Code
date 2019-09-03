public class Student 
{ 
	public static void main (String[] args) 
	{ 
		Post piazza = new ProxyInstructor(); //Students don't know that this is a fake piazza :D
		try
		{ 
			piazza.postMessage("Jerry");
			piazza.postMessage("John"); 
			piazza.postMessage("Phillips");
			piazza.postMessage("Joshua"); 
			piazza.postMessage("Tylor");
			piazza.postMessage("Anonymous"); 
		} 
		catch (Exception e) 
		{ 
			System.out.println(e.getMessage()); 
		} 
	} 
} 
