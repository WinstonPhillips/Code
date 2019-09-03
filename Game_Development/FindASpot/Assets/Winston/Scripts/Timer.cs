using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class Timer : MonoBehaviour
{
    public GameObject timerText;
    public int timer;

    // Start is called before the first frame update
    void Start()
    {
        timer = 3;
    }

    // Update is called once per frame
    void Update()
    {
        if(Time.frameCount % 60 == 0)
        {
            if(timer != 0)
            {
                timer--;
            }
			// ending game condition
			else
			{
				//we lost
				
				SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1);

			}
        }

        timerText.GetComponent<Text>().text = "Time Left: " + timer;
    }
}
