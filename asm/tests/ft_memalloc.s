; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memalloc.s                                      :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/20 23:42:19 by cglavieu          #+#    #+#              ;
;    Updated: 2015/05/21 00:38:13 by cglavieu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_memalloc

extern malloc
extern _ft_bzero

section	.text

_ft_memalloc:
	enter	0, 0
	push	rdi
	call	malloc
	cmp	rax, 0
	je	exit
	pop	rdi
	push rdi
	push	rax
	mov	rsi, rdi
	mov	rdi, rax
	call	_ft_bzero
	pop	rax

exit:
	pop rdi
	leave
	ret
