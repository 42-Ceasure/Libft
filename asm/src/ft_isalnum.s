; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalnum.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/20 23:42:19 by cglavieu          #+#    #+#              ;
;    Updated: 2015/05/22 05:23:45 by cglavieu         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global	_ft_isalnum

extern _ft_isalpha
extern _ft_isdigit

section .text

_ft_isalnum:
	call	_ft_isalpha
	cmp		rax, 1
	je		exit
	call	_ft_isdigit

exit:	
	ret
