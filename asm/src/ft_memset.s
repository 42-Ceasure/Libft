; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memset.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/20 23:42:19 by cglavieu          #+#    #+#              ;
;    Updated: 2015/05/22 05:25:33 by cglavieu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_memset

section .text

_ft_memset:
	push rdi
	cmp rdx, 0
	jle exit
	cmp	rdi, 0
	je exit
	mov rax, rsi
	mov rcx, rdx
	rep stosb

exit:
	pop rdi
	mov rax, rdi
	ret
