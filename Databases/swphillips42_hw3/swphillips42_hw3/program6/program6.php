<?php
	$con = mysql_connect ('localhost', 'root', 'coursework')
		or die('Could not Connect: ' . mysql_error());
	echo 'Connected Successfully';
	mysql_select_db('TTU') or die ('Could not select database');
	$query = 'SELECT DISTINCT TNUMBER AS TNUM2, COURSE_ID AS C_ID2, (SELECT COUNT(COURSE_ID) FROM GRADES WHERE TNUMBER = TNUM2 AND COURSE_ID = C_ID2) as ATTEMPTS, (SELECT MIN(GRADE) FROM GRADES WHERE TNUMBER = TNUM2 AND COURSE_ID = C_ID2) AS HIGHEST_GRADE FROM GRADES having ATTEMPTS>1';
	$result = mysql_query ($query) or die ('Query failed: ' . mysql_error());	
	echo "<table border=\"1\">\n";
 
	while ($row = mysql_fetch_array($result, MYSQL_ASSOC))
	{
		echo "\t<tr>\n";
		foreach ($row as $col_value)
		{
		  echo "\t\t<td>$col_value</td>\n";
		}
		echo "\t</tr>\n";
	}
	echo "</table>\n";
	mysql_free_result($result);
	mysql_close ($con);
?>
