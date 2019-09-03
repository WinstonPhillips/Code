
public class Piazza implements Post 
{ 
	@Override
	public void postMessage(String msg) 
	{ 
		System.out.println("Hi "+ msg + "! You are allowed to post here"); 
	} 
} 
