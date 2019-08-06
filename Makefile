# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 11:34:51 by vhazelnu          #+#    #+#              #
#    Updated: 2019/08/06 16:29:17 by vhazelnu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap
NAME2 = checker

LIB = -L libft/ -lft

INCLUDES = -I ./includes -I libft/includes -I libft/ft_printf/includes

SRCS = get_args.c checker.c validation.c rev_rotate.c rotate.c ssp.c libft/ft_free_two_dim_arr.c libft/ft_isascii.c libft/ft_istabspace_in_str.c \
		libft/ft_memalloc.c libft/ft_printf/ft_printf.c libft/ft_skip_whitesp.c libft/ft_strcmp.c libft/ft_strdup.c libft/ft_strsplit.c \
		libft/ft_printf/ft_symbol.c libft/ft_printf/ft_number.c libft/ft_printf/ft_conv_f.c libft/ft_printf/ft_conv_x.c libft/ft_printf/ft_conv_d.c \
		libft/ft_printf/ft_conv_p.c libft/ft_printf/ft_conv_o.c libft/ft_printf/ft_conv_u.c libft/ft_printf/width_for_f.c libft/ft_printf/ft_conv_b.c \
		libft/ft_printf/longadd.c libft/ft_printf/longmulti.c libft/ft_printf/decimal_part.c libft/ft_printf/longdiv.c libft/ft_printf/integer_part.c \
		libft/ft_printf/rounding_and_print.c libft/ft_printf/calculate_decimal.c libft/ft_printf/width.c libft/ft_printf/find_conv_or_whitesp.c \
		libft/ft_atoi.c libft/ft_atoi_base.c libft/ft_bzero.c libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_itoa_base.c \
		libft/ft_itoa_ll.c libft/ft_memcpy.c libft/ft_memset.c libft/ft_power.c libft/ft_putchar.c libft/ft_putstr.c libft/ft_realloc.c \
		libft/ft_revstr.c libft/ft_strchr.c libft/ft_strcpy.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strncpy.c \
		libft/ft_strndup.c libft/ft_strnew.c libft/ft_swap.c libft/ft_swap_str.c libft/ft_uitoa_base.c libft/iswhitesp.c libft/ft_bzero_null.c \
		libft/ft_islower.c libft/ft_isupper.c libft/ft_memdel.c libft/ft_strcat.c libft/get_next_line.c libft/ft_strsub.c

CCFL = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME2)

$(NAME2): $(SRCS)
	@make -C libft/ft_printf
	gcc $(CCFL) -o $(NAME2) $(SRCS) -g

clean:
	@make clean -C libft/ft_printf
	@rm -f $(NAME2)

fclean: clean
	@make fclean -C libft/ft_printf
	@rm -f $(NAME2)

re: fclean all
