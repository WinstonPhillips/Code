import java.util.ArrayList; 
import java.util.List; 


public class ProxyInstructor implements Post 
{ 
	private Piazza realpiazza = new Piazza(); 
	private static List<String> bannedUsers; 
	
	static
	{ 
		bannedUsers = new ArrayList<String>(); 
		bannedUsers.add("anonymous"); 
		bannedUsers.add("catch me if you can"); 
		//bannedUsers.add(""); 
		//bannedUsers.add(""); 
	} 
	
	@Override
	public void postMessage(String msg) throws Exception 
	{ 
		if(bannedUsers.contains(msg.toLowerCase())) 
		{ 
			throw new Exception("Access Denied for "+ msg+ "!!!"); 
		} 
		
		realpiazza.postMessage(msg); 
	} 

} 
