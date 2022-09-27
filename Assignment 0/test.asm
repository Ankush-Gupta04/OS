segment .data
	fmts: db "%s",0
	fmtn: db "%d",0
	msg2: db " Enter no",10,0
	msg1: db " Enter string",10,0
	msg: db "Hello",10,0
	msgn: db "",10,0


segment .bss
	string: resb 16
	number: resb 4

segment .text
	extern printf
	extern scanf
	global main
	default rel

main:
	push rbp

	lea rdi,[fmts]
	lea rsi,[msg]
	mov rax,0
	call printf

	lea rdi,[fmts]
	lea rsi,[msg1]
	mov rax,0
	call printf

	lea rdi,[fmts]
	lea rsi,[string]
	mov rax,0
	call scanf

	lea rdi,[fmts]
	lea rsi,[string]
	mov rax,0
	call printf

	lea rdi,[fmts]
	lea rsi,[msg2]
	mov rax,0
	call printf

	lea rdi,[fmtn]
	lea rsi,[number]
	mov rax,0
	call scanf

	lea rdi,[fmtn]
	mov rsi,[number]
	mov rax,0
	call printf

	mov rax, 0
	pop rbp
	ret
