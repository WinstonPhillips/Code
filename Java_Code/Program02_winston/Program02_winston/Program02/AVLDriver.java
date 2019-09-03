/* Written by Winston Phillips T00212039 */
import java.util.ArrayList;
import java.util.*;

public class AVLDriver{


   private static CD[] readMusic(String fileName) // we will loop through this and add to the tree
      {
         FileIO file = new FileIO(fileName, FileIO.FOR_READING);
         String str = file.readLine();
         ArrayList<CD> cds = new ArrayList<CD>();
         while (!file.EOF())
         {
            String title = file.readLine();
            int year = Integer.parseInt(file.readLine());
            int rating = Integer.parseInt(file.readLine());
            int numTracks = Integer.parseInt(file.readLine());
            CD cd = new CD(title, str, year, rating, numTracks);

            cds.add(cd);
            int tracks = 1;

            while (tracks <= numTracks)
            {
               String temp = file.readLine();
               String[] line = temp.split(",");
               String len = line[0];
               String songTitle = line[1];
               cd.addSong(songTitle, len);
               tracks++;
            }

            str = file.readLine();
         }

         CD[] cds_array = new CD[cds.size()];
         int i = 0;
         for(CD cd : cds)
         {
            cds_array[i] = cds.get(i);
            i++;
         }
         return cds_array;
      }

      public static void main(String[] args)
      {
         CD[] cdArray = readMusic("cds.txt");

         Command worst = new WorstCDs(); // creating our command

         AVLTree myTree = new AVLTree();

         for(CD cd : cdArray)
         {
            myTree.insert(cd);
         }

         myTree.execute(worst); // send the command 

         List<CD> cdList = ((WorstCDs) worst).getWorstCDs();

         System.out.println("Worst Rated CD's: \n");

         for(CD cd : cdList)
         {
            System.out.println(cd);
         }

         Command lng = new LongestSong(); // command for find

         myTree.execute(lng);

         Song longestSong = ((LongestSong) lng).getLongestSong();

         System.out.println("\n\nLongest Song : " + longestSong.getTitle() + " with length of " + longestSong.getLength());
      }

   }


