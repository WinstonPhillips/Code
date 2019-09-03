import java.sql.*;

public class program1{
	public static void main(String args[])
	{
		try
		{
		  Statement stmnt = null;
		  Connection conn = null;
			
		  Class.forName("com.mysql.jdbc.Driver");	// we have to access JDBC!
		  
		  conn = DriverManager.getConnection("jdbc:mysql://localhost/",
					"root", "coursework"); // we do not need a database name quite yet
		
		  System.out.println("Initial connection has been established"); // "Connection"
	
		 stmnt = conn.createStatement(); // creates a statement object for sending SQL statements to the database
		 int updateStatement = stmnt.executeUpdate("DROP DATABASE IF EXISTS TTU"); //drop if the table already exists
		 updateStatement = stmnt.executeUpdate("CREATE DATABASE TTU"); // sending this sql statement to the database!

			conn.close();  //close database
			System.out.println("Initial Connection Closed!");
		}catch (SQLException | ClassNotFoundException e)
		{
			System.out.println(e.getMessage()); // if thrown, show message
		}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		try 
		{
		// Class.forName("com.mysql.jdbc.Driver");
		 Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/TTU", "root", "coursework"); // connecting to our local database at localhost
		 
		  System.out.println("Second connection has been established!");

		  Statement stmnt  = conn.createStatement(); // for being able to send queries to local database

		 int updateStatement = stmnt.executeUpdate("CREATE TABLE STUDENTS( TNUMBER char(8) primary key, F_NAME VARCHAR(20) NOT NULL, L_NAME VARCHAR(20) NOT NULL, DateOfBirth varchar(10))  ENGINE = INNODB");

		updateStatement = stmnt.executeUpdate("INSERT INTO STUDENTS(TNUMBER, F_NAME, L_NAME, DateOfBirth) VALUES (12345678, 'John', 'Jones', '07/17/1976')"); // Extra inserted row for Tikl
	
		//updateStatement = stmnt.executeUpdate("INSERT INTO STUDENTS(TNUMBER, F_NAME, L_NAME, DateOfBirth) VALUES (87654321, 'Debra', 'Dinkle', '20181017')");	
		ResultSet rslt = stmnt.executeQuery("SELECT * FROM STUDENTS");
		
			System.out.format("%12s %-22s %-22s %9s %n", "TNUMBER", "F_NAME", "L_NAME", "DateofBirth");

		/*Now we must create objects for each tuple and display accordingly*/
	
		while(rslt.next()) // while we are still getting results (rows) from our DB
		{
			String tnum = rslt.getString("STUDENTS.TNUMBER"); // retrieve tuples and then display
			String fName = rslt.getString("STUDENTS.F_NAME");
			String lName = rslt.getString("STUDENTS.L_NAME");
			String DOB = rslt.getString("STUDENTS.DateOfBirth");
		
			System.out.format("%12s %-22s %-22s %9s %n", tnum, fName,lName,DOB);
		}	
		 
                 
			conn.close();  // close the database!

			System.out.println("Second Connection Ended!");
		}

		catch(SQLException E)
		{
			System.out.println(E.getMessage());
		}
		

}

}


