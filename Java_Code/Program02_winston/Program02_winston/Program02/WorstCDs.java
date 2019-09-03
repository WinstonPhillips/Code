import java.util.ArrayList;

public class WorstCDs implements Command{

	private ArrayList<CD> worstCDs = new ArrayList<CD>();
	private int worstRating = 5; // for example

	public void execute(Object item)
	{
		CD cd = (CD) item; // cast Object to a cd

		if(cd.getRating() == worstRating)
		{
			worstCDs.add(cd);
		}
		else if(cd.getRating() < worstRating)
		{
			worstRating = cd.getRating();
			worstCDs.add(cd);
		}
	}

	public ArrayList<CD> getWorstCDs() // returns shitty cds 
	{
		return worstCDs;
	}
}