; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strchr.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/20 23:42:19 by cglavieu          #+#    #+#              ;
;    Updated: 2015/05/21 00:38:13 by cglavieu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strchr

extern _ft_strlen

section .text

_ft_strchr:
	push rbp
	mov rbp, rsp
	call _ft_strlen
	cmp rsi, 0
	je zerocase
	mov rcx, rax
	push rdi
	inc rcx
	push rcx
	mov al, sil
	cld
	repne scasb
	pop rax
	pop rdi
	cmp rcx, 0
	je notfound
	inc rcx
	sub rax, rcx
	add rdi, rax
	mov rax, rdi
	jmp end

notfound:
	mov rax, 0
	jmp end

zerocase:
	add rdi, rax
	mov rax, rdi
	jmp end

end:
	mov rsp, rbp
	pop rbp
	ret
