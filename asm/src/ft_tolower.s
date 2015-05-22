; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_tolower.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/20 23:42:19 by cglavieu          #+#    #+#              ;
;    Updated: 2015/05/22 05:27:23 by cglavieu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global	_ft_tolower

section .text

_ft_tolower:
	mov rax, rdi
	cmp rdi, 'A'
	jl fail
	cmp rdi, 'Z'
	jg fail
	add rax, 32
	ret

fail:
	ret
