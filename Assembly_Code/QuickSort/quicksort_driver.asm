; Written by: Winston Phillips T00212039 ;

.386

.MODEL FLAT

ExitProcess PROTO NEAR32 stdcall, dwExitCode:DWORD

.STACK  4096            ; reserve 4096-byte stack

MAXLEN 			  EQU DWORD ptr 14; Easy access for Boshart

.DATA

numWords 		  DWORD 0		; total number of words

giantText 		  BYTE 1400 DUP(?)  ; giant array to contain text

inputString 	  BYTE MAXLEN DUP(?)

xString 		  BYTE "x", 0    ; for input strings


INCLUDE io.h            ; header file for input/output
INCLUDE debug.h			; for outputW macro
INCLUDE str_utils.h		; for string util Macros
INCLUDE quicksort.h

.CODE
_start:

input_loop:

	input 		inputString, MAXLEN

	compare 	inputString, xString
	cmp 		ax, 0
	je 			finish
	
	append 		inputString, giantText
	
	inc 		numWords		
	
	jmp 		input_loop
	

	
finish:
	
	output giantText
	
	
	quicksort_macro giantText, numWords,  MAXLEN
	output carriage
	output carriage
	output carriage
	
	output giantText
	
	
INVOKE  ExitProcess, 0
	
PUBLIC _start

END