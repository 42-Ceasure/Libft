; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_putchar.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/20 23:42:19 by cglavieu          #+#    #+#              ;
;    Updated: 2015/05/21 00:39:43 by cglavieu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

%define WRITE 0x2000004
	
global	_ft_putchar

section	.text

_ft_putchar:
	push rdi
	mov rsi, rsp
	mov rdx, 1
	mov rdi, 1
	mov rax, WRITE
	syscall
	jc error

exit:	
	pop rdi
	ret

error:
	mov rax, -1
	jmp exit
