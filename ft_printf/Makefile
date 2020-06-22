# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hysimok <hysimok@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/19 22:35:11 by hysimok           #+#    #+#              #
#    Updated: 2020/06/22 15:02:46 by hysimok          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c
OBJ = $(SRC:.c=.o)
INC_LINK = -I./includes
LIBFT = -L./Libft -lft

all : $(NAME)
$(NAME) : $(OBJ) libft
	cp Libft/libft.a ./$(NAME)
	ar rsc $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) $(INC_LINK) -c $< -o $(<:.c=.o)

# libft compile
libft :
	@$(MAKE) -C ./Libft all
clean :
	@$(MAKE) -C ./Libft clean
	@rm -rf ${OBJ}
fclean : clean
	@$(MAKE) -C ./Libft fclean
	@rm -rf $(NAME)
re : fclean all
.PHONY: all clean fclean re libft