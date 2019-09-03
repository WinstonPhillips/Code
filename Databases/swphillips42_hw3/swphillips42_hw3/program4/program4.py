import sys
import MySQLdb

try:
	conn = MySQLdb.connect (host = "localhost", user =  "root", passwd = "coursework", db = "TTU")
except MySQLdb.Error, e:
	print "Error %d: %s" % (e.args[0], e.args[1])
	sys.exit (1)
	
cursor = conn.cursor ()
	#time tto execute commands!!
cursor.execute("DROP TABLE IF EXISTS GRADES") #we want to run this multiple times
cursor.execute("CREATE TABLE GRADES(TNUMBER char(8), COURSE_ID char(7), SEMESTER char(1), check (SEMESTER in ('F', 'S')), YEAR numeric(4,0), GRADE char(1), check (GRADE in ('A', 'B', 'C', 'D', 'F')), FOREIGN KEY(TNUMBER) REFERENCES STUDENTS(TNUMBER)) ENGINE=INNODB")
#cursor.execute("ALTER TABLE GRADES MODIFY TNUMBER CHAR NULL")
cursor.execute("INSERT into GRADES(TNUMBER, COURSE_ID, SEMESTER, YEAR, GRADE) VALUES ('00012233', 'CSC3300', 'F', '2013', 'A'), ('00023052', 'MAT1910', 'F', '2011', 'C'), ('00001203', 'CSC1310', 'S', '2013', 'A'), ('00120330', 'MAT1910', 'S', '2012', 'D'), ('00120330', 'CSC1310', 'S', '2012', 'F'), ('00120330', 'MAT1910', 'F', '2012', 'A'), ('00120330', 'CSC1310', 'F', '2012', 'D'), ('00012233', 'CSC1310', 'F', '2011', 'C'), ('00012233', 'CSC1310', 'S', '2012', 'C'), ('00012233', 'CSC1310', 'F', '2013', 'B'), ('00001203', 'CSC2310', 'S', '2012', 'D')")
cursor.execute("commit")	
cursor.execute("SELECT * from GRADES")

print "TNUMBER  COURSE_ID SEMESTER YEAR GRADE"

while (1):
	row = cursor.fetchone()
	if row == None:
		break
	print "%s %2s %6s %8s %2s" % (row[0], row[1], row[2], row[3], row[4])

