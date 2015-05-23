; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strchr.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/20 23:42:19 by cglavieu          #+#    #+#              ;
;    Updated: 2015/05/22 05:35:59 by cglavieu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strchr

extern _ft_strlen

section .text

_ft_strchr:
	cmp rdi, 0
	je _ret0
	push rdi
	call _ft_strlen
	pop rdi
	mov rcx, rax
	inc rcx
	mov rax, rsi
	repne scasb
	cmp rcx, 0
	je _ret0
	dec rdi
	mov rax, rdi
	ret

_ret0:
	mov rax, 0
	ret
