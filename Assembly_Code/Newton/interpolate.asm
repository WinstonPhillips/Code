
.386
.MODEL FLAT

INCLUDE debug.h
INCLUDE float.h
INCLUDE compute_b.h

array_address 	EQU 	[ebp+14]
	Degree		EQU  	[ebp+12]
	X_Coor 		EQU		[ebp+8]

PUBLIC interpolate_proc

.data

testNUM 				real4 ?
number					WORD ?
string  	    		BYTE " ", 0
answer_prompt			BYTE "Answer is: ", 0



.CODE

interpolate_proc PROC NEAR32

	push 	ebp 
	mov 	ebp, esp
	push 	ecx
	push 	eax
	pushf		; pushing done

	
	mov cx, Degree ; for (x-xn)
	
	fldz		; push zero on the floating point stack so we don't get errors with initial addition
	

	initial_loop:
			
			dec cx
			
			cmp cx, 0
			jl exit_code 	; we are done
			
			mov dx, cx		; dx will be our second counter
			
			fld1		; for our initial multiplication
			
		loop_until_b:
			
			cmp dx, 0
			jl get_b		; parentheses are done
			
		
			fld real4 ptr X_Coor  
			
			
			mov ebx, array_address
			mov ax, 0
			mov ax, 8
			mov number, dx
			mul number 		;  multiply first counter by 8   
			add bx, ax
			fld real4 ptr [ebx]  ; load x_n into floating point stack
			mov dx, number	; to get our dx (counter back), gets overwritten 
				
			fsub ; x - x_n
	
			dec dx		; decrement counter
			
			fmul		; multiply
			
			jmp loop_until_b
			
		get_b:
			
			inc 	cx	; cx is now our degree we are going to send
			compute_b dword ptr array_address, cx, word ptr 0   ; the b value is now on the floatkng point stack
			dec 	cx	;cx back to normal for counter
			
			
			fmul	; bn * ()()()
			
			fadd	; add to previous calculation
			
			jmp 	initial_loop



exit_code:
	
	output answer_prompt ; prompt for our answer
	compute_b array_address, word ptr 0, word ptr 0 ; for final b zero addition
	fadd
	
	
	fst testNUM
	ftoa testNUM, word ptr 7, word ptr 10, string
	output string
	
	output carriage
	

	pop 	eax
	pop 	ecx
	popf
	mov 	esp, ebp
	pop 	ebp
	ret 	10
	
interpolate_proc ENDP

END