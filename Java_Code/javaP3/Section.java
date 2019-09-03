
public class Section  // a section will have multiple studdents
{
   private int sectionID;
   private Students students; // students object
   private String file;

   public Section(int sectionID, int total_num_labs)
   {
      this.sectionID = sectionID;
      file = "section" + sectionID + ".txt";
      students = new Students(file, total_num_labs);
   }

   //DO THIS
   //several short methods must be implemented (note: some have been done, see below) // this is the controller class
   public String partnerList(int labID)
   {
      return students.partnerList(labID);
   }

   public String getStudentName(int studentID)
   {
      return students.getStudentName(studentID);
   }
   
   public String studentInfo(int studentID)
   {
       return students.studentInfo(studentID);
   }

   public void addLab(int studentID)
   {
      students.addLab(studentID);
   }

   //no work below this point
   public void computePartners(Random rand)
   {
      students.computePartners(rand);
   }

   public void writeFile(double[] grade_constants, int total_num_labs)
   {
      students.writeFile(file, grade_constants, total_num_labs); // looks as if students would be the model and sections in the controller 
   }

   public int getNumStudents()
   {
      return students.getNumStudents();
   }

   public int getNumLabs()
   {
      return students.getNumLabs();
   }

   public void setGrade(int lab, int student, char grade)
   {
      students.setGrade(lab, student, grade);
   }

   public void setInactive(int studentID)
   {
      students.setInactive(studentID);
   }

   public void setNotPresent(int studentID, int labID)
   {
      students.setNotPresent(studentID,labID);
   }

   public int getPartnerID(int studentID, int labID)
   {
      return students.getPartnerID(studentID,labID);
   }

}