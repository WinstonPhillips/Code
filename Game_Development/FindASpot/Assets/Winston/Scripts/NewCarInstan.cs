using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class NewCarInstan : MonoBehaviour
{
	public GameObject touringcar_dark;
	
    private void OnTriggerEnter2D(Collider2D collider){	
	 Debug.Log("Collision Detected");
		
		
		Debug.Log("Car Instantiated");
		Instantiate(touringcar_dark);
		
	
	 }
}
