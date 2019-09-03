;for our recursion to compute b
.386
.MODEL FLAT

INCLUDE debug.h
INCLUDE float.h
	
	address EQU [ebp+12]
	n 		EQU [ebp+10]
	m	    EQU [ebp+8]
	
	
	
PUBLIC compute_b_proc

.DATA


.CODE
          
compute_b_proc PROC NEAR32
	
	
	push 	ebp 

	mov 	ebp, esp
	
	push 	edx
	push 	ecx	
	push 	eax  
	pushf	; pushing done
	
	
	mov 	cx, n
	mov 	dx, m
	cmp		dx, cx
	je 		m_n_equal	; m and n are equal : BASE CASE
	
	mov 	cx, m
	add		cx, 1	; add 1 to m
	mov 	dx, n
	pushd 	address
	push	dx
	push 	cx
	call 	compute_b_proc
	
	mov 	dx, n
	dec 	dx
	mov 	cx, m
	pushd 	address
	push 	dx		;push n-1
	push 	cx		; push m
	call	compute_b_proc
	
	fsub
	

x_n:

	mov eax, 0
	mov edx, 0
	
	mov 	ebx, address
	mov 	ax, n
	mov 	dx, 8
	mul		dx			; to get to x value
	add		bx, ax		
	
	fld 	real4 ptr [ebx] 
	
	
x_m:

	mov eax, 0
	mov edx, 0
	
	mov 	ebx, address
	mov 	ax, m
	mov 	dx, 8
	mul		dx			; to get to x value
	add		bx, ax
	
	fld 	real4 ptr [ebx]
	
	
x_n_minus_x_m:

	fsub		; now on floating point stack
	fdiv		; FINAL COMPUTATION
	
	
	jmp		exit_code
	
	
m_n_equal:

	mov 	ebx, address
	mov 	eax, 0
	mov 	edx, 0
	mov 	ax, n
	mov 	dx, 8
	mul		dx	
	add 	ax, 4
	add 	bx, ax
	
	fld 	real4 ptr [ebx]	; xn in  x(0)
	
	
		
exit_code:
			
			popf
			pop eax
			pop ecx
			pop edx
			mov esp, ebp
			pop ebp
			ret 8
		
	
	
		
compute_b_proc ENDP

END