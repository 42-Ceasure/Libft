; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memalloc.s                                      :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/20 23:42:19 by cglavieu          #+#    #+#              ;
;    Updated: 2015/05/22 05:19:10 by cglavieu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_memalloc

extern _malloc
extern _ft_bzero

section	.text

_ft_memalloc:
	push	rdi
	call	_malloc
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
	ret
