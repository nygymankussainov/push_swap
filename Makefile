# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 11:34:51 by vhazelnu          #+#    #+#              #
#    Updated: 2019/10/23 16:48:53 by vhazelnu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LOG_NOCOLOR = \033[0m
LOG_GREEN = \033[32m

ARCHIVE = libftpushswap.a

PUSH_SWAP = push_swap
CHECKER = checker

LIB = libft/ft_printf
LIB_A = libft/libft.a $(LIB)/libftprintf.a

OBJDIR = obj

INCLUDES = -I ./includes -I libft/includes -I $(LIB)/includes

SRCS = get_args.c validation.c rev_rotate.c rotate.c ssp.c papb.c get_intarr.c shit_sort.c \
		divide_stack.c arr_indexation.c find_best_case.c three_sort.c five_sort.c \
		get_args.c validation.c rev_rotate.c rotate.c ssp.c papb.c get_intarr.c arr_indexation.c find_best_case.c \

OBJ = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o)) \
		$(OBJDIR)/push_swap.o $(OBJDIR)/checker.o

CCFL = -Wall -Wextra -Werror

.PHONY: all clean fclean re obj_dir library

all: obj_dir library $(ARCHIVE) $(PUSH_SWAP) $(CHECKER)

obj_dir:
	@mkdir -p $(OBJDIR)

library:
	@make -sC $(LIB)

$(ARCHIVE): $(OBJ)
	@ar rc $(ARCHIVE) $(OBJ)
	@echo "$(LOG_GREEN)Push_swap has compiled successfully!$(LOG_NOCOLOR)"
	@ranlib $(ARCHIVE)
	
$(OBJDIR)/%.o: %.c
	@gcc $(CCFL) -o $@ -c $< $(INCLUDES)

$(PUSH_SWAP): $(OBJ)
	@gcc $(CCFL) -o $(PUSH_SWAP) $(PUSH_SWAP).c $(ARCHIVE) $(LIB_A)

$(CHECKER): $(OBJ)
	@gcc $(CCFL) -o $(CHECKER) $(CHECKER).c $(ARCHIVE) $(LIB_A)

clean:
	@make clean -sC $(LIB)
	@/bin/rm -rf $(OBJDIR)

fclean: clean
	@make fclean -sC $(LIB)
	@/bin/rm -f $(ARCHIVE)
	@/bin/rm -f $(PUSH_SWAP)
	@/bin/rm -f $(CHECKER)

re: fclean all
