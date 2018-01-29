# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: mmoya <mmoya@student.le-101.fr>            +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/26 19:06:36 by mmoya        #+#   ##    ##    #+#        #
#    Updated: 2018/01/29 20:41:08 by mmoya       ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = ft_ls

SRCPATH = ./srcs/

SRCS =	file.c \
		ft_ls.c \
		info.c \
		list.c \
		ls_print.c \
		readder.c

OBJ = $(SRCS:.c=.o)

HEAD = -I ./includes/

FLAGS = -Wall -Wextra -Werror -g

LIBPATH = ./libft/

LIB = libft.a

MSG_LIB= "\033[1m o--->  \033[32m[ LIBFT ]\033[0m"

MSG_LIBEND= "\033[1m o---<  \033[30m[ END ]\033[0m\n"

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): $(LIBPATH)$(LIB) $(OBJ)
	@gcc $(FLAGS) $(HEAD) $(LIBPATH)$(LIB) $(OBJ) -o $(NAME)
	@echo " \033[1;34m$(NAME) \033[37mDONE\033[0m"

$(LIBPATH)$(LIB):
	@echo $(MSG_LIB)
	@$(MAKE) -C $(LIBPATH)
	@echo $(MSG_LIBEND)

%.o: $(SRCPATH)%.c
	@echo "\033[1mCompiled :	\033[34m\"$*\"\033[0m"
	@gcc $(FLAGS) $(HEAD) -c $< -o $@

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[1mRemoved :  \033[31m\"*.o\"\033[0m"
	@echo $(MSG_LIB)
	@$(MAKE) fclean -C $(LIBPATH)
	@echo $(MSG_LIBEND)

fclean: clean
	@/bin/rm -f $(NAME)
	@echo $(MSG_LIB)
	@echo $(MSG_LIBEND)
	@echo "\033[1mRemoved :  \033[31m\"$(NAME)\"\033[0m"

re: fclean all
