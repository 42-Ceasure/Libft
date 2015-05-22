; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strnew.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/20 23:42:19 by cglavieu          #+#    #+#              ;
;    Updated: 2015/05/22 05:27:19 by cglavieu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global	_ft_strnew

extern	_ft_memalloc

section	.text

_ft_strnew:
	enter	0, 0
	push rdi
	inc	rdi
	call	_ft_memalloc
	pop rdi
	leave
	ret
