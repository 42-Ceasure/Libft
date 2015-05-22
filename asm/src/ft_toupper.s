; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_toupper.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/20 23:42:19 by cglavieu          #+#    #+#              ;
;    Updated: 2015/05/22 05:27:27 by cglavieu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global	_ft_toupper

section .text

_ft_toupper:
	mov rax, rdi
	cmp rdi, 'a'
	jl fail
	cmp rdi, 'z'
	jg fail
	sub rax, 32
	ret

fail:
	ret
