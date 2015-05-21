section .data
lol:
	.str db "je suis un ouf", 10
	.len equ $ - lol.str

section .text
	global start
	global _main
	extern _printf

start:
	call _main
	ret

_main:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	lea rdi, [rel lol.str]
	call _printf
	leave
	ret