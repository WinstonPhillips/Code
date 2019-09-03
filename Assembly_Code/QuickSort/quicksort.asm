;for our recursion to compute b
.386
.MODEL FLAT

INCLUDE debug.h
INCLUDE str_utils.h

PUBLIC quicksort_start_proc, quicksort_proc, swap_proc, partition_proc

.CODE			; only need one declaration of .CODE
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

giantText_addr 		EQU [ebp+16]
MAXLEN				EQU [ebp+12]
numWords			EQU	[ebp+8]


quicksort_start_proc PROC NEAR32

push 	ebp 
mov 	ebp, esp
push 	ecx
push 	eax
push 	edi
push 	esi
pushf	
	
	mov eax, MAXLEN
	sub eax, 2
	mov MAXLEN, eax
	
	mov eax, 0
	mov eax, numWords
	dec eax
	mov numWords, eax
	
	push giantText_addr
	push MAXLEN
	push DWORD PTR 0
	push numWords
	call quicksort_proc


popf
pop 	esi
pop 	edi
pop 	eax
pop 	ecx
mov 	esp, ebp
pop 	ebp
ret 	12


quicksort_start_proc ENDP
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
giantText_addr 	EQU  [ebp+20]
MAXLEN 			EQU  [ebp+16]
lowz			EQU  [ebp+12]
highz			EQU  [ebp+8]

quicksort_proc PROC NEAR32

push 	ebp 
mov 	ebp, esp
push 	ecx
push 	eax
push 	ebx
push 	edi
push 	esi
pushf	
	
	; First, compare low to high ;
		
		mov eax, 0
		mov ecx, 0
	
		mov eax, lowz
		mov ecx, highz
	
		cmp eax, ecx    		; if (low < high)
		jge dantes_Gates
		
		push giantText_addr
		push MAXLEN
		push DWORD PTR lowz 		
		push DWORD PTR highz  	
		call partition_proc
		
		mov eax, ebx
		dec eax
				
		push DWORD PTR giantText_addr
		push DWORD PTR MAXLEN
		push DWORD PTR lowz
		push eax
		call quicksort_proc
		
		mov eax, ebx
		inc eax
		
		push DWORD PTR giantText_addr
		push DWORD PTR MAXLEN
		push eax
		push DWORD PTR highz
		call quicksort_proc
		
	
	
	dantes_Gates:

popf
pop 	esi
pop 	edi
pop 	ebx
pop 	eax
pop 	ecx
mov 	esp, ebp
pop 	ebp
ret 	16

quicksort_proc ENDP
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

giantText_addr 	EQU  [ebp+20]
MAXLEN 			EQU  [ebp+16]
lowz			EQU  [ebp+12]
highz			EQU  [ebp+8]


partition_proc PROC NEAR32

push 	ebp 
mov 	ebp, esp
push 	ecx
push 	edx
push 	eax
push 	edi
push 	esi
pushf	

	; the first thing we need to do is set up our pivot and get i = (low -1);
	; Do this by getting edi to our high point ;
	
		mov ebx, highz		;put our high value in ebx
		
		mov eax, 0
		mov eax, MAXLEN
		
		mul ebx
		
		mov edi, giantText_addr
		add edi, eax
		
		mov ebx, 0
		mov ebx, lowz
		dec ebx		; ebx now contains low -1, or i
	
	; Now, we begin our loop ;
	;First, set up counter	;
	
		mov ecx, lowz	; j counter ( j = low)
		dec ecx			; for loop
	
	proc_loop:
	
		inc ecx
		
		mov eax,  highz
		dec eax
		
		cmp ecx, eax
		jg done
		
		mov eax, MAXLEN
		mul ecx
		
		mov esi, giantText_addr
		add esi, eax
		
		mov eax, 0
		compare [esi], [edi]
		
		cmp ax, 0
		jge proc_loop
		
		inc ebx 		; i++
		push DWORD PTR giantText_addr
		push DWORD PTR MAXLEN
		push ebx		; pushing i
		push ecx		; push j
		call swap_proc
		
		jmp proc_loop
		
	done:
	
		inc ebx			; increment in
		
		push DWORD PTR giantText_addr
		push DWORD PTR MAXLEN
		push ebx
		push DWORD PTR highz
		call swap_proc
	
	
	
popf
pop 	esi
pop 	edi
pop 	eax
pop 	edx
pop 	ecx
mov 	esp, ebp
pop 	ebp
ret 	16

partition_proc ENDP
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
giantText_addr EQU [ebp+20]
MAXLEN EQU [ebp+16]
pos2 EQU [ebp+12]
pos1 EQU [ebp+8]

swap_proc PROC NEAR32

push 	ebp 
mov 	ebp, esp
push 	ecx
push 	eax
push 	ebx
push 	edi
push 	esi
pushf	

;outputD pos2
;outputD pos1
	
	; get pos1 * MAXLEN
		mov edx, MAXLEN
		mov eax, pos1
		mul edx			; pos1 * 14 is now in eax
		mov pos1, eax	; pos1 now contains our correct value
		
	; get pos2 * MAXLEN
		mov edx, MAXLEN
		mov eax, pos2
		mul edx			; pos2 * 14 is now in eax
		mov pos2, eax	; pos2 now contains our correct value
		
		mov ecx, MAXLEN		; set counter for the temp_storage_loop
		
		mov esi, giantText_addr		; move our giant text to esi for loading to al register
		
		add esi, pos2				; get to the position we need to "copy" the word
		
		
		mov ebx, esp				; store esp in edx for after loop
		
	
	temp_storage_loop:
		
			cmp ecx, 0
			je continue
			
			lodsb
			dec esp
			mov [esp], al
			
			dec ecx
			
			jmp temp_storage_loop
		
	continue:
	
		mov esp, ebx 	; move esp back to what it was
	
			
		
		mov esi, giantText_addr		

		mov edi, giantText_addr		; the "rep movsb" will put the text we moved text to edi
		
		
		mov eax, pos1 				; get our positioning 
		mov edx, pos2				; get our positioning
		
		add esi, eax				
		add edi, edx
		
	
		mov ecx, MAXLEN				; our counter for rep movsb
		
		rep movsb					; do the FIRST move
		
		
		
		mov ecx, MAXLEN				; our counter for below
		
		mov edi, giantText_addr		; we want the text stored to be put into our destination
		
	
		add edi, eax				; get to the position where we want to put our text stored in the stack
		
		
		
		mov ebx, esp				; store esp in ebx for after loop
	
	storing_loop:
	
		cmp ecx, 0
		je 	done
	
		dec esp
		mov al, [esp]
		
		stosb
		
		dec ecx
		
		jmp storing_loop
		
	done:

	mov esp, ebx 	; move esp back to what it was


popf
pop 	esi
pop 	edi
pop 	ebx
pop		eax
pop 	ecx
mov 	esp, ebp
pop 	ebp
ret 	16

swap_proc ENDP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;















END