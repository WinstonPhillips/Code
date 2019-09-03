
		#requires the tdbc connector for TCL
	package require tdbc::mysql

	#here we will create a database for manipulation - linked to TTU 

	tdbc::mysql::connection create thatGoodDB -database TTU -user root -password coursework 	

	set m [thatGoodDB prepare {SELECT * from STUDENTS where L_NAME LIKE 'D%'}] 
	
 

	set output [$m allrows]

	foreach row $output {
		foreach {col_name col_val} $row {

			puts -nonewline [format " %2s %2s " $col_name $col_val]
		}
		puts ""
	}

	thatGoodDB close
