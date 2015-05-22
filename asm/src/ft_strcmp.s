; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/20 23:42:19 by cglavieu          #+#    #+#              ;
;    Updated: 2015/05/22 05:28:47 by cglavieu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strcmp

section .text

_ft_strcmp:
	jmp        .loop

.start:
	cmp        al, 0 ; end of s1
	je        .exit
	inc        rdi
	inc        rsi

.loop:
	xor        rax, rax
	xor        rcx, rcx
	mov        al, [rdi] ; char
	mov        cl, [rsi] ; char
	cmp        al, cl
	je        .start

.exit:
	sub        rax, rcx
	ret
