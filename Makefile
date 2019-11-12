# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 11:34:51 by vhazelnu          #+#    #+#              #
#    Updated: 2019/11/12 14:36:53 by vhazelnu         ###   ########.fr        #
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
SRCDIR = src

INCLUDES = -I ./ -I libft/ -I $(LIB)/

SRC = get_args.c validation.c rev_rotate.c rotate.c ssp.c papb.c get_intarr.c sort_stack.c \
		divide_stack.c arr_indexation.c find_best_case.c three_sort.c five_sort.c \
		
SRCS = $(addprefix $(SRCDIR)/, $(SRC))

OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o)) \
		$(OBJDIR)/$(PUSH_SWAP).o $(OBJDIR)/$(CHECKER).o

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
	
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@gcc $(CCFL) -o $@ -c $< $(INCLUDES)

$(PUSH_SWAP): $(OBJ)
	@gcc $(CCFL) -o $(PUSH_SWAP) $(SRCDIR)/$(PUSH_SWAP).c $(ARCHIVE) $(LIB_A) $(INCLUDES)

$(CHECKER): $(OBJ)
	@gcc $(CCFL) -o $(CHECKER) $(SRCDIR)/$(CHECKER).c $(ARCHIVE) $(LIB_A) $(INCLUDES)

clean:
	@make clean -sC $(LIB)
	@/bin/rm -rf $(OBJDIR)

fclean: clean
	@make fclean -sC $(LIB)
	@/bin/rm -f $(ARCHIVE)
	@/bin/rm -f $(PUSH_SWAP)
	@/bin/rm -f $(CHECKER)

re: fclean all
