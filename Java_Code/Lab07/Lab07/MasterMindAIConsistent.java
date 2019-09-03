import java.util.ArrayList;
import java.util.List;

public class MasterMindAIConsistent implements MasterMindAI
{
   private MasterMind game;

   public MasterMindAIConsistent(MasterMind game)  
   {
      this.game = game;
   }

   //DO THIS
   //is the guess consistent with all previous results?
   //that is, if you compare your random guess to a previous guess, do you get the same number of black and white buttons?
   //don't just check your random guess against the secret guess until you get a good result, LAST THING TO DO
   private boolean analyzeGuess(Guess nextGuess) // next guess is the random guess
   {
      List<Guess> guesses = game.getGuesses();  //get all previous guesses from the game

      int num_guesses = guesses.size();

    int[] prevSecCompare = game.getResult(guesses.get(num_guesses));

       for (int i = 0; i < guesses.size(); i++)
       {
           

         int[] nextAllPrev = game.getResult(guesses.get(i), nextGuess); // array from comparing current guess with a previous guess

         if (nextAllPrev[0] != prevSecCompare[0]  || nextAllPrev[1] != prevSecCompare[1])  
         {
            return false;
         }

      
       }

      return true; 
   }

   //DO THIS
   public Guess nextGuess(int guess_id)
   {
      List<Guess> guesses = game.getGuesses(); // gets all previous guesses from the game
      int num_guesses = guesses.size();
      Guess nextGuess = null; // random guess to be sent to analyzeGuess


      if (guesses.size() > 0)
      {

         Guess trialGuess = null;
      
         boolean good = false;
      
          while (!good)
          {
            trialGuess = makeRandomGuess(guess_id); 

            good = analyzeGuess(trialGuess);
             
            
          }

          nextGuess = trialGuess;

       }
       else
       {   
          nextGuess = makeRandomGuess(guess_id); // below
      }

return nextGuess;

   }
   //DO THIS
   //use the Random class to make a randomly generated guess
   private static Guess makeRandomGuess(int guess_id)
   {
      Guess randomGuess = new Guess(guess_id);
      Random random = Random.getRandomNumberGenerator();



      for (int i = 0; i < 4; i++)
      {
         int random_int = random.randomInt(1,7);
       
         randomGuess.addGuess(random_int);
      }

      
      return randomGuess;
   }
}