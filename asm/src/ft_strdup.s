; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/20 23:42:19 by cglavieu          #+#    #+#              ;
;    Updated: 2015/05/22 05:18:55 by cglavieu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strdup

extern _malloc
extern _ft_strlen
extern _ft_memcpy

section .text
	
_ft_strdup:
	push rdi
	mov rax, 0
	cmp rdi, 0
	je exit					;all the above is protection
	call _ft_strlen
	inc rax					; for '\0'
	mov r12, rax			; save in r12 because r12 is a callee saved (r12-r15)
	mov rdi, r12
	call _malloc
	cmp rax, 0
	je exit
	mov rdi, rax 			; dst = malloc(s1)
	pop rsi					; src = s1;
	mov rdx, r12			; rdx = strlen
	call _ft_memcpy
	ret

exit:
	pop rdi
	ret

