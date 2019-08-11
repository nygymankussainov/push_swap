# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 11:34:51 by vhazelnu          #+#    #+#              #
#    Updated: 2019/08/11 14:08:11 by vhazelnu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ARCHIVE_PS = push_swap.a
ARCHIVE_CH = checker.a

PUSH_SWAP = push_swap
CHECKER = checker

LIB = libft/ft_printf
LIB_A = libft/libft.a $(LIB)/libftprintf.a

INCLUDES = -I ./includes -I libft/includes -I $(LIB)/includes

SRC_PS = get_args.c validation.c rev_rotate.c rotate.c ssp.c papb.c push_swap.c get_intarr.c shit_sort.c \
		divide_stack.c arr_indexation.c find_best_case.c \

SRC_CH = get_args.c checker.c validation.c rev_rotate.c rotate.c ssp.c papb.c get_intarr.c arr_indexation.c find_best_case.c \

OBJ_CH = $(SRC_CH:.c=.o)
OBJ_PS = $(SRC_PS:.c=.o)

CCFL = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(ARCHIVE_PS) $(ARCHIVE_CH) $(PUSH_SWAP) $(CHECKER)

$(ARCHIVE_PS): $(OBJ_PS)
	@make -C $(LIB)
	@ar rc $(ARCHIVE_PS) $(OBJ_PS)
	@ranlib $(ARCHIVE_PS)

$(ARCHIVE_CH): $(OBJ_CH)
	@ar rc $(ARCHIVE_CH) $(OBJ_CH)
	@ranlib $(ARCHIVE_CH)
	
%.o: %.c $(INCLUDES)
	@gcc $(CCFL) -c $<

$(PUSH_SWAP): $(OBJ_PS)
	@gcc $(CCFL) -o $(PUSH_SWAP) $(ARCHIVE_PS) $(LIB_A) -g

$(CHECKER): $(OBJ_CH)
	@gcc $(CCFL) -o $(CHECKER) $(ARCHIVE_CH) $(LIB_A) -g

clean:
	@make clean -C $(LIB)
	@rm -f $(ARCHIVE_PS)
	@rm -f $(ARCHIVE_CH)
	@rm -f $(PUSH_SWAP)
	@rm -f $(CHECKER)
	@rm -f $(OBJ_CH)
	@rm -f $(OBJ_PS)

fclean: clean
	@make fclean -C $(LIB)

re: fclean all
