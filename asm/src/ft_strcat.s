; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcat.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/20 23:42:19 by cglavieu          #+#    #+#              ;
;    Updated: 2015/05/21 00:38:13 by cglavieu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global	_ft_strcat

extern	_ft_strlen
extern	_ft_memcpy

section .text

_ft_strcat:
	push rdi
	mov rax, 0
	cmp rdi, 0
	je exit
	cmp rsi, 0
	je exit					;all of the above is security
	call _ft_strlen			;strlen(s1)
	mov r12, rax			; lenght of s1 in r12
	mov rdi, rsi
	call _ft_strlen	
	inc rax					;for '\0'
	mov rdx, rax			;lenght of s2 in rdx
	pop rdi					;put initial value of rdi in rdi
	push rdi
	add rdi, r12			;go to end of chain
	call _ft_memcpy

exit:
	pop rax
	ret
