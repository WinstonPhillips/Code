package ki;

public abstract class KeyedItem
{
	//create single instance variable of type Comparable
	final Comparable Key;
  
   public KeyedItem(Comparable key) 
   {
      Key = key;
   }  

   public Comparable getKey() 
   {
	   return Key;
	}  

	//Use Comparable toString() method
   public String toString()
   {
	   return Key.toString(); // ??
	}
}