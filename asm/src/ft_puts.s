; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_puts.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/20 23:42:19 by cglavieu          #+#    #+#              ;
;    Updated: 2015/05/21 00:38:16 by cglavieu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_puts

extern _ft_strlen

section .text

_ft_puts:
	cmp        rdi, 0 		; s != NULL ?
	je        .null
	xor        rax, rax 	; ret = 0
	push    rdi 			; save s

.print:
	call    _ft_strlen
	mov        rdx, rax 	; len
	mov        rdi, 1 		; STDOUT
	pop        rsi 			; char *s (mov rdi, rsi)
	mov        rax, 0x2000004 ; write
	syscall
	jmp        .line

.null:
	lea        rcx, [rel null] ; first byte of (null)
	mov        rdi, 1
	mov        rsi, rcx
	mov        rdx, null_l	; longueur de null
	mov        rax, 0x2000004
	syscall

.line:
	mov        rdi, 0xA		   ;10 = ascii value of \n
	lea        rcx, [rel char] ; write(1, &c, 1)
	mov        [rcx], rdi	   ;could use dil (8 bit version of rdi since only \n)
	mov        rdi, 1 		; fd
	mov        rsi, rcx
	mov        rdx, 1
	mov        rax, 0x2000004
	syscall
	mov rax, 10
	ret

section .data

null:	    db "(null)"
null_l:	    equ $-null 			; string lenght

section    .bss

char:	    resb 0x1
