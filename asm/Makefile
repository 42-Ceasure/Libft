# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/20 22:54:46 by cglavieu          #+#    #+#              #
#    Updated: 2015/05/20 23:04:12 by cglavieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:			all, clean, fclean, re

CC =			nasm

CFLAG =			-f macho64 --prefix _

NAME =			libfts.a

SRCDIR =		./src/

OBJDIR =		./obj/

LIBDIR =		./lib/

SRCFIL =		ft_bzero.s	ft_isdigit.s	ft_isalpha.s	ft_isalnum.s\
				ft_isascii.s	ft_isprint.s	ft_toupper.s	ft_tolower.s\
				ft_isupper.s	ft_islower.s	ft_putchar.s	ft_strlen.s\
				ft_memset.s		ft_memcpy.s		ft_strdup.s		ft_strcat.s\
				ft_cat.s 		ft_puts.s\

OBJFIL =		$(SRCFIL:.s=.o)

LIBFIL =		libftasm.h

SRC =			$(addprefix $(SRCDIR),$(SRCFIL))

OBJ =			$(addprefix $(OBJDIR),$(OBJFIL))

LIB =			$(addprefix $(LIBDIR),$(LIBFIL))

all:			$(NAME)

$(NAME):		$(OBJ)
				@ar rcs $@ $^
				@echo "libftasm created"

$(OBJDIR)%.o:	$(SRCDIR)%.s
				@mkdir -p $(OBJDIR)
				@$(CC) $(CFLAG) -I$(LIBDIR)  $< -o $@

clean:
				@rm -f $(OBJ)
				@echo "clean done"
fclean:			
				@rm -f $(OBJ)
				@rm -f $(NAME)
				@echo "fclean done"

re: 			fclean all