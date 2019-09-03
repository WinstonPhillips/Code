local status, err = pcall (function ()
	env = assert (require "luasql.mysql".mysql(), "CANNOT LOAD LIBRARY")
	
	con = assert (env:connect ("TTU", "root", "coursework"), "CANNOT CONNECT TO DATABASE")
	cur = assert (con:execute "SELECT DISTINCT F_NAME, L_NAME, if (GRADE in('A','B','C', 'D'), 'YES', 'NO') as Answer from STUDENTS NATURAL JOIN GRADES WHERE COURSE_ID = 'CSC1310' UNION (SELECT F_NAME, L_NAME, 'NO' as Answer FROM STUDENTS NATURAL JOIN GRADES WHERE COURSE_ID != 'CSC1310')", "ERROR EXECUTING QUERY")
	end)
if not status then
	print ("Error: " .. err)
	os.exit ()
end
print ("F_NAME   L_NAME    CAN_TAKE")
print ("-------+---------+----------")
row = cur:fetch ({}, "a")
while row do
	print (string.format("%5s %10s %6s", row.F_NAME, row.L_NAME, row.Answer)) 
	row = cur:fetch (row, "a")
end 

cur:close ()
con:close ()
env:close ()
