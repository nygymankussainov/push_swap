# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 11:34:51 by vhazelnu          #+#    #+#              #
#    Updated: 2019/08/09 17:06:39 by vhazelnu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap
NAME2 = checker

LIB = -L libft/ -lft

INCLUDES = -I ./includes -I libft/includes -I libft/ft_printf/includes

SRCS1 = get_args.c validation.c rev_rotate.c rotate.c ssp.c papb.c libft/ft_free_two_dim_arr.c push_swap.c print_stack.c get_intarr.c shit_sort.c \
		divide_stack.c arr_indexation.c find_best_case.c \
		libft/ft_isascii.c libft/ft_istabspace_in_str.c libft/ft_intarrcat.c \
		libft/ft_memalloc.c libft/ft_printf/ft_printf.c libft/ft_skip_whitesp.c libft/ft_strcmp.c libft/ft_strdup.c libft/ft_strsplit.c \
		libft/ft_printf/ft_symbol.c libft/ft_printf/ft_number.c libft/ft_printf/ft_conv_f.c libft/ft_printf/ft_conv_x.c libft/ft_printf/ft_conv_d.c \
		libft/ft_printf/ft_conv_p.c libft/ft_printf/ft_conv_o.c libft/ft_printf/ft_conv_u.c libft/ft_printf/width_for_f.c libft/ft_printf/ft_conv_b.c \
		libft/ft_printf/longadd.c libft/ft_printf/longmulti.c libft/ft_printf/decimal_part.c libft/ft_printf/longdiv.c libft/ft_printf/integer_part.c \
		libft/ft_printf/rounding_and_print.c libft/ft_printf/calculate_decimal.c libft/ft_printf/width.c libft/ft_printf/find_conv_or_whitesp.c \
		libft/ft_atoi.c libft/ft_atoi_base.c libft/ft_bzero.c libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_itoa_base.c libft/ft_intarrlen.c \
		libft/ft_itoa_ll.c libft/ft_memcpy.c libft/ft_memset.c libft/ft_power.c libft/ft_putchar.c libft/ft_putstr.c libft/ft_realloc.c \
		libft/ft_revstr.c libft/ft_strchr.c libft/ft_strcpy.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strncpy.c \
		libft/ft_strndup.c libft/ft_strnew.c libft/ft_swap.c libft/ft_swap_str.c libft/ft_uitoa_base.c libft/iswhitesp.c libft/ft_bzero_null.c \
		libft/ft_islower.c libft/ft_isupper.c libft/ft_memdel.c libft/ft_strcat.c libft/get_next_line.c libft/ft_strsub.c

SRCS2 = get_args.c checker.c validation.c rev_rotate.c rotate.c ssp.c papb.c libft/ft_free_two_dim_arr.c print_stack.c get_intarr.c shit_sort.c \
		divide_stack.c arr_indexation.c find_best_case.c \
		libft/ft_isascii.c libft/ft_istabspace_in_str.c libft/ft_intarrcat.c \
		libft/ft_memalloc.c libft/ft_printf/ft_printf.c libft/ft_skip_whitesp.c libft/ft_strcmp.c libft/ft_strdup.c libft/ft_strsplit.c \
		libft/ft_printf/ft_symbol.c libft/ft_printf/ft_number.c libft/ft_printf/ft_conv_f.c libft/ft_printf/ft_conv_x.c libft/ft_printf/ft_conv_d.c \
		libft/ft_printf/ft_conv_p.c libft/ft_printf/ft_conv_o.c libft/ft_printf/ft_conv_u.c libft/ft_printf/width_for_f.c libft/ft_printf/ft_conv_b.c \
		libft/ft_printf/longadd.c libft/ft_printf/longmulti.c libft/ft_printf/decimal_part.c libft/ft_printf/longdiv.c libft/ft_printf/integer_part.c \
		libft/ft_printf/rounding_and_print.c libft/ft_printf/calculate_decimal.c libft/ft_printf/width.c libft/ft_printf/find_conv_or_whitesp.c \
		libft/ft_atoi.c libft/ft_atoi_base.c libft/ft_bzero.c libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_itoa_base.c libft/ft_intarrlen.c \
		libft/ft_itoa_ll.c libft/ft_memcpy.c libft/ft_memset.c libft/ft_power.c libft/ft_putchar.c libft/ft_putstr.c libft/ft_realloc.c \
		libft/ft_revstr.c libft/ft_strchr.c libft/ft_strcpy.c libft/ft_strjoin.c libft/ft_strlen.c libft/ft_strncpy.c \
		libft/ft_strndup.c libft/ft_strnew.c libft/ft_swap.c libft/ft_swap_str.c libft/ft_uitoa_base.c libft/iswhitesp.c libft/ft_bzero_null.c \
		libft/ft_islower.c libft/ft_isupper.c libft/ft_memdel.c libft/ft_strcat.c libft/get_next_line.c libft/ft_strsub.c

CCFL = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME1) $(NAME2)

$(NAME1): $(SRCS)
	@make -C libft/ft_printf
	@gcc $(CCFL) -o $(NAME1) $(SRCS1) -g

$(NAME2): $(SRCS)
	@gcc $(CCFL) -o $(NAME2) $(SRCS2) -g

clean:
	@make clean -C libft/ft_printf
	@rm -f $(NAME1)
	@rm -f $(NAME2)

fclean: clean
	@make fclean -C libft/ft_printf

re: fclean all
