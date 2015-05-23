; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/20 23:42:19 by cglavieu          #+#    #+#              ;
;    Updated: 2015/05/22 07:42:23 by cglavieu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strcpy

section .text

_ft_strcpy:
	mov		r8, rdi
.loop:
	mov		cl, [rsi]
	mov		[rdi], cl
	cmp		cl, 0
	jz		.ret
	inc		rdi
	inc		rsi
	jmp		.loop
.ret:
	mov		rax, r8
	ret