TITLE Program Template     (template.asm)
; Author: Max Zimmer	
; Last Modified: 1/18/2022
; OSU email address: zimmemax@oregonstate.edu
; Course number/section: 001
; Assignment Number: 2              Due Date: 1/23/2022
; Description: a program designed to take in a number (1-46), n, from the user
;then output n amount of of numbers in the fibonacci sequence
INCLUDE Irvine32.inc
; (insert constant definitions here)
.data

intro BYTE "Hello, please input your name: ", 0
numInput BYTE ", please enter a num between 1-46: ", 0
hello BYTE "Hello ", 0
numInputError BYTE "Incorrect input, enter again: ", 0
n DWORD ?
username BYTE 33 DUP(0)
space BYTE "     ", 0
goodbye BYTE "GOODBYE AND HAVE A GOOD DAY: ", 0

counter DWORD ?
temp DWORD ?



; (insert variable definitions here)

.code
main PROC
; (insert executable instructions here)
;print intro
mov		edx, OFFSET intro
call	WriteString
;read in username
mov		edx, OFFSET username
mov		ecx, 32
call	ReadString
;prompt user to enter a num between 1-46 and store val

InputLoop:
	mov edx, OFFSET hello
	call WriteString
	mov edx, OFFSET username
	call WriteString
	mov edx, OFFSET numInput
	call WriteString
	call ReadInt
	mov n, eax
	mov eax, n
	cmp eax, 0
	jl InputLoop
	cmp eax, 47
	JGE InputLoop
	jmp endLoop

endLoop:
;intitialze registers for fib sequence

mov ecx, n
mov eax, 0
mov ebx, 1
mov edx, 0
mov temp, 0
mov counter, 0

;loop for fiba sequence
FibLoop:

	call WriteDec
	mov edx, eax
	add eax, ebx
	; final solution in eax, previous val in ebx
	mov ebx, edx

	;compare counter
	inc counter
	cmp counter, 4
	jge NewLine
	mov edx, OFFSET space
	call WriteString
	loop FibLoop
	jmp Done

;case if there has been 4 num outputs
Newline:
	call Crlf
	mov counter, 0
	loop FibLoop
;say goodbye to user
Done:

call crlf
mov edx, OFFSET goodbye
call writestring
mov edx, OFFSET username
call writestring







	


	
	

;setup if








exit ; exit to operating system
main ENDP
; (insert additional procedures here)
END main