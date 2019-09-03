; Written by: Winston Phillips T00212039 ;

.386

.MODEL FLAT

ExitProcess PROTO NEAR32 stdcall, dwExitCode:DWORD

.STACK  4096            ; reserve 4096-byte stack


.DATA

NUM_POINTS			  WORD ? 	; for iterating through array

POLYNOMIAL_DEGREE	  WORD ? ; stores the degree of the polynomial

X_COORDINATE		  REAL4 ? ; x-coordinate of the desired interpolated y

tol					  REAL4 0.00001  ; for sorting points

POINTS_ARRAY  		  REAL4 40 DUP(?)	; matrix for holding our points

inputPoint 			  REAL4 ?	; for atof float number
	
inputPrompt 		  BYTE 	" ", 0 ; for setting elements in MATRIX

inputString		  	  BYTE 13  DUP(?)	; string for atof and ftoa procedures

sorted_prompt		  BYTE "Sorted Points: ", 0

unsorted_prompt		  BYTE "Unsorted Points: ", 0


INCLUDE io.h            ; header file for input/output
INCLUDE debug.h			; for outputW macro
INCLUDE float.h
INCLUDE sort_points.h
INCLUDE interpolate.h


.CODE
_start:

input	inputString, WORD PTR 8	; get input for X_COORDINATE
atof    inputString, X_COORDINATE

inputW	inputPrompt, POLYNOMIAL_DEGREE	; get the polynomial degree

lea 			ebx, POINTS_ARRAY	
mov 			NUM_POINTS, 0		; counter for how many points we have
	
inputPointsLoop:
	
		
	
	input inputString, WORD PTR 8
	
	cmp 		inputString, "q"
	je 			done
	
	atof 		inputString, inputPoint
	mov 		ecx, inputPoint
	mov 		[ebx], ecx		; add the float to the POINTS_ARRAY
	add 		ebx, 4
	
	ftoa 		inputPoint, WORD PTR 3, WORD PTR 10, inputString
	inc			NUM_POINTS
	
	jmp inputPointsLoop
	

done:

	mov dx, 0
	mov ax, NUM_POINTS
	mov cx, 2
	div cx
	mov NUM_POINTS, ax	; now we have the appropriate amount of points
	

	output unsorted_prompt
	output carriage
	print_points POINTS_ARRAY, NUM_POINTS
	
	output carriage
	output carriage
	
	sort_points POINTS_ARRAY, X_COORDINATE, tol, NUM_POINTS 	; sort the points 
	
	output sorted_prompt
	output carriage
	print_points POINTS_ARRAY, NUM_POINTS
	
	
	interpolate_macro POINTS_ARRAY, POLYNOMIAL_DEGREE, X_COORDINATE   ; array, degree, x_coordinate
	
INVOKE  ExitProcess, 0
	
PUBLIC _start

END


















