#

.PHONY: clean, fclean, re

CC			=	gcc

CFLAG		=	-Wall -Wextra -Werror

NAME		=	libft.a

INCDIR		=	./inc/
SRCDIR		=	./src/
OBJDIR		=	./obj/

SRCFIL		=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memchr.c ft_memccpy.c ft_memmove.c \
				ft_memcmp.c ft_strlen.c ft_strdup.c
OBJFIL		=	$(SRCFIL:.c=.o)

SRC			=	$(addprefix $(SRCDIR),$(SRCFIL))
OBJ			=	$(addprefix $(OBJDIR),$(OBJFIL))


all				:	$(NAME)

$(NAME)			:	$(OBJ)
					@ar rcs $@ $^

$(OBJDIR)%.o	:	$(SRCDIR)%.c
					@mkdir -p $(OBJDIR)
					@$(CC) $(CFLAG) -I $(INCDIR) -o $@ -c $<

clean			:	
					@rm -Rf  $(OBJDIR)

fclean			: 
					@rm -Rf  $(OBJDIR)
					@rm -f $(NAME)

re				:	fclean all
