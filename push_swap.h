/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:26:58 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/11 14:11:57 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf/ft_printf.h"

typedef struct	s_stack
{
	int			*arr;
	int			last;
	int			size;
}				t_stack;

char			**get_args(char **str);
int				validation(char **str);
t_stack			*get_intarr(char **str);
int				issorted(t_stack *stack);
int				isonly_whitesp(char *str);
void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack **b);
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **a, t_stack **b);
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);
void			shit_sort(t_stack **a, t_stack **b);
void			divide_stack(t_stack **a, t_stack **b);
int				arr_indexation(char ***str, int *min, int min_i, t_stack **tmp);
int				find_best_case(t_stack *a, t_stack *b);
int				find_closest(t_stack *a, t_stack *b, int i);

#endif
