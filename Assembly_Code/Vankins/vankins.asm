; Written by: Winston Phillips T00212039 ;

.386

.MODEL FLAT

ExitProcess PROTO NEAR32 stdcall, dwExitCode:DWORD

.STACK  4096            ; reserve 4096-byte stack


.DATA

ROWS 			WORD ?  ; Number of Rows 

COLS 			WORD ? ; Number of Cols

row 			WORD ?	; singular row for loops

col 			WORD ?	; singular col	for loops

ITERATION 		WORD ? 	; for loops

COUNTER 		WORD ? 	; COLS x ROWS 

NumToGet 		WORD ? ; for getElement MACRO

NumToPlace 		WORD ? ; for setElement MACRO

MATRIX  		WORD 500 DUP(?)	; matrix for initial ouptut

SOL_MATRIX 		WORD 500 DUP(?) 	; solution matrix

solMatrixNumRight WORD ? ; for solution matrix loops

solMatrixNumDown  WORD ? ; for solution matrix loops

regMatrixNum 	  WORD ? ; for solution matrix loops

loc 			  WORD ? ; for solution matrix loops

prompt3 		  BYTE 	" ", 0 ; for setting elements in MATRIX

testText 		  BYTE 13  DUP(?) 	; might have to use to get a good looking matrix

r 				  BYTE "r", 0		; to display r in our path

d 				  BYTE "d", 0		; to display d in our path



INCLUDE io.h            ; header file for input/output
INCLUDE debug.h			; for outputW macro


.CODE
_start: 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
setMatrixFromInput MACRO 	matrix_addr, loc

	mov 	[ebx], loc

		

		ENDM
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
getElement MACRO  matrix_addr, row, col, loc

	mov 	dx, row
	sub 	dx, 1
	
	mov 	ax, COLS
	
	mul 	dx		; multiplies row by total numbe rof COLS and stores result in ax
	
	mov 	dx, col
	sub 	dx, 1
	add 	ax, dx		; We now have our index number
	
	add ax, ax			; same as multiplying by 2
		
	add bx, ax		; get to the index that we need through ebx
	
	mov dx, [ebx]		; to avoid memory-to-memory reference, puts the number of the index into dx
	
	mov loc, dx			; puts dx into loc 
	
	
		ENDM

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
setElement MACRO  matrix_addr, row, col, loc

	
	mov 	dx, row
	sub 	dx, 1
	
	mov 	ax, COLS
	
	mul 	dx		; multiplies row by total numbe rof COLS and stores result in ax
	
	mov		dx, col
	sub 	dx, 1
	add 	ax, dx		; adds call to (row-1) x COLS
	
	
	add ax, ax			; same as multiplying by 2
	
	add bx, ax		; get to the index that we need through ebx
	
	mov dx, loc		;place our Number to Set in the Solutions array
	
	mov [ebx], dx
	

			ENDM
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

		
	inputW prompt3, ROWS 	;obtains rows 
		;outputW ROWS
		
	inputW prompt3, COLS	; obtains columns
		;outputW COLS
		
	mov 		ax, ROWS
	
	mov 		dx, COLS
		
	mul 		dx			; should get ROWS x COLS
	
	mov 		COUNTER, ax
	
	mov 		cx, 0 		; counter for our loop
	
	lea 		ebx, MATRIX
	
	
set_array_elements_loop:

	
	inputW prompt3, ax		; get input from user/text file and place it into ax 
	
	
	setMatrixFromInput ebx, ax
	
	add 		ebx, 2		; for our next loop, add 2 because we are dealing with words

	inc			cx			; increment our ecx counter
	
	cmp 		cx, COUNTER ; compare our counter until equel to ROWS x COLS
	
	jl			set_array_elements_loop
	

;;;;;;;;;;;;;;;;;;; CLEAN OUTPUT IN MATRIX FORM ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


	lea 		ebx, MATRIX		; for below test
	mov 		cx, 0			; for overall comparison (ROWS x COLS) for clean output

	output carriage				; go ahead and move to the next line
	
	
output_loop_1:  	

	mov dx, col
	
	cmp 		dx, COLS
	
	jne 		regularOuput
	
	mov 		col, 0
	
	output carriage
	
	regularOuput:
	
		mov 		dx, [ebx]	; my problem
		
		itoa 		testText, dx  
		
		output		testText
		
		add 		ebx, 2
		
		inc 		col
		
		inc 		cx
		
		cmp 		cx, COUNTER 	; are we at ROWS x COLS ?
		
		jl 			output_loop_1
		
		output 		carriage
	
;;;;;;;;;;;;;;;;;;;;;;;;place last element of MATRIX into SOL_MATRIX;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	mov 		dx, COLS		
	mov 		ax, ROWS
	mov 		col, dx
	mov 		row, ax
	lea 		ebx, MATRIX
	
	getElement	ebx, row, col, NumToGet
	
	mov 		ax, NumToGet
	mov 		NumToPlace, ax
	
	mov 		dx, COLS		; place last element of MATRIX into SOL_MATRIX	
	mov 		ax, ROWS
	mov 		col, dx
	mov 		row, ax
	lea 		ebx, SOL_MATRIX
	
	setElement	ebx, row, col, NumToPlace		; the copying to last index is done
		
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	
	mov 		ax, ROWS	; we are starting at the bottom left corner of the matrix
	mov			row, ax                  
	mov 		ax, COLS
	mov 		col, ax
	
	
	mov ITERATION, 0
	
	
	
solution_matrix_loop:

		mov bx, COUNTER
		cmp ITERATION, bx
		je done_2
		
		
		lea ebx, MATRIX
		
		getElement ebx, row, col, regMatrixNum		; we are fetching last element of our regular Matrix
		
		mov cx, col
		add cx, 1			; to go right
		
		cmp cx, COLS
		jg make_solMatrixNumRight_Zero
		
		lea ebx, SOL_MATRIX
		
		getElement ebx, row, cx, solMatrixNumRight	; obtain the number to the right on the solution's matrix
			jmp continue	; to avoid below label
		
		make_solMatrixNumRight_Zero:
				
				mov solMatrixNumRight, 0
				
				
		continue:
		mov cx, row
		add cx, 1
		
		lea ebx, SOL_MATRIX
		
		getElement	ebx, cx, col, solMatrixNumDown	; obtain the number below the solution's matrix
		
		mov ax, regMatrixNum
		
		add solMatrixNumRight, ax
		add solMatrixNumDown, ax
		mov ax, solMatrixNumRight		; a load into ax for comparison purposes
		
		cmp solMatrixNumDown, ax
		jg	addFromDown
		
		addFromRight:
				
				lea ebx, SOL_MATRIX
				
				setElement ebx, row, col, solMatrixNumRight
				
				inc ITERATION
				
				dec col
		
				jmp Check_Column
		
		addFromDown:
		
				lea ebx, SOL_MATRIX
				
				setElement ebx, row, col, solMatrixNumDown
				
				inc ITERATION
				
				dec col
				
		
		Check_Column:
			
				cmp col, 0
				jg solution_matrix_loop
				mov bx, COLS 
				mov col, bx
				dec row
				jmp solution_matrix_loop
				
				
				
				
				
		
done_2:			; 	to display the solutions matrix

		
	lea 		ebx, SOL_MATRIX	; for below output
	mov 		cx, 0			; for overall comparison (ROWS x COLS) for clean output


	output carriage				; go ahead and move to the next line
	
	

output_loop_2:  	

	mov 		dx, col
	
	cmp 		dx, COLS
	
	jne 		solutionsOutput
	
	mov 		col, 0
	
	output carriage
	
	solutionsOutput:
	
		mov 		dx, [ebx]	; my problem
		
		itoa 		testText, dx  
		
		output		testText
		
		add 		ebx, 2
		
		inc 		col
		
		inc 		cx
		
		cmp 		cx, COUNTER 	; are we at ROWS x COLS ?
		
		jl 			output_loop_2
		
		
	output carriage	
	output carriage
	mov row, 1			; starting in row 1, column 1
	mov col, 1
	
path_loop:

	mov bx, row
	cmp bx, ROWS
	jg 	done_3		; our rows are okay
	
	mov bx, col
	cmp bx, COLS
	jg 	done_3
	
	
	lea ebx, SOL_MATRIX
	mov cx, col
	inc cx
	getElement ebx, row, cx, solMatrixNumRight	; obtain the number to the right
	
	mov bx, COLS		; we need to compare our current column with overall cols, to make sure the number to the right may be zero
	cmp col, bx
	jl continueToRows
	mov solMatrixNumRight, 0	; our column = COLS, meaning it should be zero
	
	
	continueToRows:
	lea ebx, SOL_MATRIX
	mov cx, row
	inc cx
	getElement ebx, cx, col, solMatrixNumDown	; obtain the number below
	
	mov bx, ROWS		; we need to compare our current row with overall ROWS, to make sure the number below may be zero
	cmp row, bx
	jl continueToAddition
	mov solMatrixNumDown, 0		; our row = ROWS, so we set the number underneath to = 0
	
	continueToAddition:
	mov cx, solMatrixNumRight
	cmp cx, solMatrixNumDown
	jg goRight
	
	goDown:
		inc row
		output d
		jmp path_loop
		
	
	goRight:
		inc col
		output r
		jmp path_loop
	
	
	
done_3:

	output carriage
	output carriage

INVOKE  ExitProcess, 0
	
PUBLIC _start

END
	
	
	
		
	

	

	