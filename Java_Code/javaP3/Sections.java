import java.util.ArrayList;

public class Sections
{
   private ArrayList<Section> sections; // a list of sections

   private double[] grade_constants;
   private int total_num_labs;

   //all sections should use the same random number generator
   private Random rand;
   
   public Sections(int num_sections, double[] grade_constants, int total_num_labs)
   {
      this.grade_constants = grade_constants;
      sections = new ArrayList<Section>();

      for (int i = 1; i <= num_sections; i++)
      {
         Section section = new Section(i, total_num_labs);
         sections.add(section);
      }

      rand = Random.getRandomNumberGenerator(); 
   }

   //DO THIS
   //several short methods must be implemented (note: some have been done, see below) // now we are writing methods as they pertain to Section class

   public String partnerList(int sectionID, int labID)
   {
      if (sectionID < 1 || sectionID > sections.size())
      {
         return "";
      }

      Section section = sections.get(sectionID - 1);

      return section.partnerList(labID);
   }

   public String getStudentName(int sectionID, int studentID)
   {
      Section section = sections.get(sectionID - 1);
      return section.getStudentName(studentID);
   }
   
   public String studentInfo(int sectionID, int studentID)
   {
      Section section = sections.get(sectionID - 1);
      return section.studentInfo(studentID);
   }

   //no work below this point
   public void computePartners(int sectionID)
   {
      if (sectionID <= 0 || sectionID > getNumSections())
      {
         return;
      }

      Section section = sections.get(sectionID - 1);
      section.computePartners(rand); // important 
   }

   public void writeFiles()
   {
      for (Section section : sections)
      {
         section.writeFile(grade_constants, total_num_labs);
      }
   }

   public void addLab(int sectionID)
   {
      sections.get(sectionID-1).addLab(sectionID); // maybe?
   }

   public int getNumStudents(int sectionID)
   {
      return sections.get(sectionID-1).getNumStudents();
   }

   public int getNumLabs(int sectionID)
   {
     return sections.get(sectionID-1).getNumLabs(); // for now  //return sections.get(sectionID).getNumLabs
   }

   public void setGrade(int sectionID, int lab, int student, char grade)
   {
      Section section = sections.get(sectionID - 1);
      section.setGrade(lab,student,grade);
   }

   public void setInactive(int sectionID, int studentID)
   {
      sections.get(sectionID-1).setInactive(studentID);
   }

   public void setNotPresent(int sectionID, int studentID, int labID)
   {
      sections.get(sectionID-1).setNotPresent(studentID, labID);
   }
   public int getNumSections()
   {
      return sections.size();
   }

   public int getPartnerID(int sectionID, int studentID, int labID)
   {
      return sections.get(sectionID-1).getPartnerID(studentID,labID);
   }

}