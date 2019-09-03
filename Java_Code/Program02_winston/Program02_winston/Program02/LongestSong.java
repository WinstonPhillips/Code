public class LongestSong implements Command{

	Song longestSong = null; // song to display
	int thatGoodGood = 0; // for measuring longest song
	
	public void execute(Object object)
	{
		CD cd = (CD) object;

		for (int i = 0; i < cd.getNumberOfTracks(); i++)
		{
			Song newSong = cd.getSong(i);

			if(newSong.getLength() > thatGoodGood)
			{
				this.longestSong = newSong;
				this.thatGoodGood = newSong.getLength();
			}
		}
	
	}

	public Song getLongestSong()
	{
		return longestSong;
	}
}