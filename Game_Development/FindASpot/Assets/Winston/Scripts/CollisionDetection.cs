using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;



public class CollisionDetection : MonoBehaviour
{  
	
	private void OnTriggerEnter2D(Collider2D collider){	
	
		
		Debug.Log("Collision Detected");
		SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1);
		
		
	
	 }
}
