# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hysimok <hysimok@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/19 22:35:11 by hysimok           #+#    #+#              #
#    Updated: 2020/07/31 19:13:24 by hysimok          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
# FLAGS = -Wall -Wextra -Werror
SRC =	ft_printf.c \
		srcs/ft_treat_flags.c \
		srcs/ft_putchar.c \
		srcs/ft_sanity_check.c \
		srcs/ft_branch_type.c \
		srcs/ft_treat_chrstr.c \
		srcs/ft_treat_width.c \
		srcs/ft_treat_pointer.c \
		srcs/ft_ull_base.c
OBJ = $(SRC:.c=.o)
INC_LINK = -I./includes
LIBFT = -L./Libft -lft

all : $(NAME)
$(NAME) : $(OBJ) libft
	cp Libft/libft.a ./$(NAME)
	ar rsc $(NAME) $(OBJ)

%.o: %.c
	#gcc $(FLAGS) $(INC_LINK) -c $< -o $(<:.c=.o)
	gcc $(INC_LINK) -c $< -o $(<:.c=.o)

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