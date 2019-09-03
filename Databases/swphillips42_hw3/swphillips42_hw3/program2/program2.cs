using System;
using System.Data;
using MySql.Data.MySqlClient;

public class program2{
	public static void Main(string[] args)
	{
		string connectionString = "Server=localhost;" + "Database=TTU;" + "User ID=root;" +  "Password=coursework;" + "Pooling=false";
	
		IDbConnection dbcon = new MySqlConnection(connectionString);

		dbcon.Open();

		IDbCommand dbcmd = dbcon.CreateCommand();

		string sql = "insert into STUDENTS (TNUMBER, F_NAME, L_NAME, DateOfBirth) VALUES ('00012233', 'John', 'Smith', '01/26/1870'), ('00023052', 'Jane', 'Doe', '04/24/1986'), ('00120330', 'Ivan', 'Ivanoff', '02/25/1974'), ('00001203', 'Billy', 'Williams', '09/19/1992')";

		dbcmd.CommandText = sql;
		IDataReader reader = dbcmd.ExecuteReader();
		
		reader.Close();
///////////////////////////////////////////////////////////////////////////////////////////

		IDbCommand querComm = dbcon.CreateCommand();

		string query = "Select TNUMBER, F_NAME, L_NAME, DateofBirth from STUDENTS";

		querComm.CommandText = query;		

		reader = querComm.ExecuteReader(); // now we are trying to display
		Console.Write("TNUMBER F_NAME L_NAME DateOFBirth\n");
		Console.Write("-------+------+------+--------------\n");

		while(reader.Read())
		{
	          string tNum = (string) reader["TNUMBER"];
		  //	int yoyo = Int32.Parse(tNum);
		  string FirstName = (string) reader["F_NAME"];
		  string LastName = (string) reader["L_NAME"];
		  string DOB = reader["DateOfBirth"].ToString();
	
		  Console.Write(string.Format(tNum + " " + FirstName + " " + LastName + " " + DOB));
	          
                  Console.WriteLine();
		}

		
		//cleannnn
		reader.Close();
		dbcmd.Dispose();
		dbcon.Close();
		querComm.Dispose();		
}

}











			 
