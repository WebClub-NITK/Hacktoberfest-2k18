%include"io.mac"

section .data					;messages to be printed
input db "Enter the number",0
output db "th fibonocci number is ",0

section .bss					;variable declaration section
number resd 1
temp resd 1

section .text					;main program starts here 
global _start
_start:
	PutStr input
	GetLInt ecx
	mov [number],ecx
	mov eax,1
	mov ebx,1
	call fibo				;calls fibonocci number

print:						;prints the nthfibonocci number
	PutLInt [number]
	PutStr output
	PutLInt eax
	nwln

done:						;exits out of the program
	.EXIT

fibo:						;comes here when the fibo label is called		
	cmp ecx,2				;compares if the number we needed reached or not
	jg fibo1
	ret

fibo1:						;Logic for fibonocci number
	mov [temp],eax
	add eax,ebx
	mov ebx,[temp]
	sub ecx,1
	jmp fibo				;jumps back to fibonocci after the loop is executed

	
