; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalpha.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/20 23:42:19 by cglavieu          #+#    #+#              ;
;    Updated: 2015/05/21 00:39:43 by cglavieu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global	_ft_isalpha

section .text

_ft_isalpha:
	cmp	rdi, 'A'
	jl false
	cmp rdi, 'z'
	jg false
	cmp rdi, 'Z'
	jg min
	jmp true

min:
	cmp rdi, 'a'
	jl false
	jmp true


true:
	mov rax, 1
	ret
	
false:
	mov rax, 0
	ret
