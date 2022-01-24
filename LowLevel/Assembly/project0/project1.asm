TITLE Program program1     (program1.asm)

; Author: Max Zimmer
; Last Modified: 1/13/2022
; OSU email address: zimmemax@oregonstate.edu
; Course number/section: CS271001
; Assignment Number:         1        Due Date: 1/16/2022
; Description Below:
;This program is intented to tell the user of my name and the name of the program
;Then, the user will enter 2 natural numbers, the first larger than the second
;Next, I will calculate the sum, quotient, difference, and product and print out the results to the user
;Lastly, for extra credit I will print out the square number 1 and 2

INCLUDE Irvine32.inc

; (insert constant definitions here)

.data

; (insert variable definitions here)
intro BYTE "Hello, my name is Max. This is program1", 0
instructions BYTE "You will enter 2 numbers (first larger than the second) to make this program work", 0
enter_message BYTE "Enter nums: ", 0
add_message BYTE "Addition: ", 0
subtract_message BYTE "Subraction: ", 0
division_message BYTE "Quotient: ", 0
remainder_message BYTE "Remainder: ", 0
mult_message BYTE "Product: ", 0
square_message1 BYTE "Extra Credit-Square of num 1 is: ", 0
square_message2 BYTE "Extra Credit-Square of num 2 is: ", 0
exit_message BYTE "You better be amazed!!!!!!!! GOODBYE", 0
num1 DWORD ?
num2 DWORD ?
sum DWORD ?
difference DWORD ?
quotient DWORD ?
remainder DWORD ?
product DWORD ?
square DWORD ?



.code
main PROC

; (insert executable instructions here)
;intro message
mov edx, OFFSET intro
call WriteString
call Crlf

;instructions message
mov edx, OFFSET instructions
call WriteString
call Crlf

;taking in first number from user
mov edx, OFFSET enter_message
call WriteString
call ReadInt
mov num1, eax
call Crlf

;taking in second num from user
mov edx, OFFSET enter_message
call WriteString
call ReadInt
mov num2, eax
call Crlf

;calculating and printing the sum 
mov eax, num1
mov ebx, num2
add eax, ebx
mov edx, OFFSET add_message
mov sum, eax
call WriteString
call WriteDec
call Crlf

;calculating and printing the difference
mov eax, num1
mov ebx, num2
sub eax, ebx
mov difference, eax
mov edx, OFFSET subtract_message
call WriteString
call WriteDec
call Crlf

;calculating and printing the product
mov eax, num1
mov ebx, num2
mul ebx
mov product, eax
mov edx, OFFSET mult_message
call WriteString
call WriteDec
call Crlf

;calculating remainder and quotient
mov eax, num1
mov ebx, num2
cdq
div ebx
mov quotient, eax
mov remainder, edx

;printing the quotient
mov edx, OFFSET division_message
mov eax, quotient
call WriteString
call WriteDec
call Crlf

;printing the remainder
mov edx, OFFSET remainder_message
mov eax, remainder
call WriteString
call WriteDec
call Crlf

;calculating and printing sqaure of num1
mov eax, num1
mov ebx, num1
mul ebx
mov square, eax
mov edx, OFFSET square_message1
call WriteString
call WriteDec
call Crlf

;calculating and printing sqaure of num2
mov eax, num2
mov ebx, num2
mul ebx
mov square, eax
mov edx, OFFSET square_message2
call WriteString
call WriteDec
call Crlf

;printing the exit message
mov edx, OFFSET exit_message
call Crlf
call Crlf
call WriteString
call Crlf














	exit	; exit to operating system
main ENDP

; (insert additional procedures here)

END main
