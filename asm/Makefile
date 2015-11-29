# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/20 22:54:46 by cglavieu          #+#    #+#              #
#    Updated: 2015/05/26 03:02:24 by cglavieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:			all, clean, fclean, re

CC =			nasm

CFLAG =			-f macho64

NAME =			libfts.a

SRC =			ft_bzero.s	ft_isdigit.s	ft_isalpha.s	ft_isalnum.s\
				ft_isascii.s	ft_isprint.s	ft_toupper.s	ft_tolower.s\
				ft_isupper.s	ft_islower.s	ft_putchar.s	ft_strlen.s\
				ft_memset.s		ft_memcpy.s		ft_strdup.s		ft_strcat.s\
				ft_cat.s 		ft_puts.s 		ft_memalloc.s 	ft_strchr.s\
				ft_strclr.s 	ft_strcmp.s 	ft_strcpy.s 	ft_strequ.s\
				ft_strncpy.s 	ft_strnew.s

SRCDIR = ./src/
SRCFILL = $(addprefix $(SRCDIR),$(SRC))

OBJ = $(SRC:.s=.o)
OBJDIR = ./obj/
OBJFILL = $(addprefix $(OBJDIR),$(OBJ))

INC = ./inc/

all:			$(NAME)

$(NAME):		$(OBJFILL)
				@ar rcs $@ $^

$(OBJDIR)%.o:	$(SRCDIR)%.s
				@mkdir -p $(OBJDIR)
				@$(CC) $(CFLAG) -I $(INC) $< -o $@

clean:
				@rm -rf $(OBJDIR)

fclean:			clean
				@rm -f $(NAME)

re: 			fclean all
