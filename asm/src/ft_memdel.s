; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memdel.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/20 23:42:19 by cglavieu          #+#    #+#              ;
;    Updated: 2015/05/22 05:23:38 by cglavieu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_memdel

extern _free

section .text

_ft_memdel:
	cmp rdi, 0
	je .end
	push rdi
	call _free

.end:
	ret
