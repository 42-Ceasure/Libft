; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isascii.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/20 23:42:19 by cglavieu          #+#    #+#              ;
;    Updated: 2015/05/22 05:24:24 by cglavieu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_isascii

section .text

_ft_isascii:
	mov rax, 1
	cmp rdi, 0
	jl	exit
	cmp rdi, 127
	jg exit
	ret

exit:
	mov rax, 0
	ret
