; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/20 23:42:19 by cglavieu          #+#    #+#              ;
;    Updated: 2015/05/21 00:38:13 by cglavieu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strcpy

extern _ft_strlen

section .text

_ft_strcpy:
	xor al, al
	mov r9, rdi
	mov r10, rsi
	mov rdi, rsi
	call _ft_strlen
	mov rcx, rax
	mov rdi, r9
	mov rsi, r10
	cld
	rep movsb
	mov rax, r9
	ret
