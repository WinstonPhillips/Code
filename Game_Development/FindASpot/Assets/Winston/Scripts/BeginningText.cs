using UnityEngine;
using System.Collections;

public class BeginningText : MonoBehaviour
{
	GUIStyle style = new GUIStyle();
	
	void Start(){
			
		
	}
    void OnGUI()
    {
		
		style.fontSize = 70;
			
		style.normal.textColor = Color.black;
		
		style.fontSize = 70;
			
		style.normal.textColor = Color.black;
		
        GUI.Label(new Rect((Screen.width-150)/2, ((Screen.height-150)/2)-50, 150, 150), "FIND THE PARKING SPACE!");
 	  
    }
}
