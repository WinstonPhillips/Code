import java.util.Iterator;
import bst.*;
import ki.KeyedItem;
//import java.util.Arrays;
import java.lang.reflect.Array;

public class TreeSort
{
   //convenience method
   public static KeyedItem[] treeSort(KeyedItem[] sort)	
   {

   	//easier to use a KeyedItem array than Comparable


   	  Class myClass = sort.getClass();


	  KeyedItem[] newArray = (KeyedItem[]) Array.newInstance(myClass.getComponentType(),sort.length);  // nuts

      BinarySearchTree myBST = new BinarySearchTree(true,true); // trues for parameters for our requirements

	      for (int i = 0; i < sort.length; i++)
	      {
	      	newArray[i] = sort[i];
	      }
	      
	      for (int i = 0; i < sort.length; i++)
	      {
	      	myBST.insert(newArray[i]); // inserting the original array passed into the tree
	      }

      TreeIterator myIterator = myBST.iterator();

      myIterator.setInorder();		// set the elements in order in the BST
     
	  int i = 0;

		  while (myBST.iterator().hasNext() == true) 
		  {
		  		newArray[i] = (KeyedItem) myIterator.next();
		  		i++;
		  }
	  
	   return newArray;
   }
   	  
  

   public static KeyedItem[] treeSort(KeyedItem[] sort, int n)
   {
      //easier to use a KeyedItem array than Comparable


   	  Class myClass = sort.getClass();


	  KeyedItem[] newArray = (KeyedItem[]) Array.newInstance(myClass.getComponentType(),n);  // nuts



	  
	  //create a new Binary Search Tree 
      //a balanced tree ensures logn inserts for nlogn sort

      BinarySearchTree myBST = new BinarySearchTree(true,true); // trues for parameters for our requirementss
         	

      for (int i = 0; i < n; i++)
      {
      	myBST.insert(sort[i]); // inserting the original array passed into the tree
      }

      TreeIterator myIterator = myBST.iterator();

      myIterator.setInorder();
     
	  int i = 0;

	  while (myBST.iterator().hasNext() == true) 
	  {
	  		newArray[i] = (KeyedItem) myIterator.next();
	  		i++;
	  }
	  
	   return newArray;
   }
  

}