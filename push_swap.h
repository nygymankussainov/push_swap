/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:26:58 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/06 22:08:54 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf/ft_printf.h"

char	**get_args(char **str);
int		validation(char **str);
int		*get_intarr(char **str);
int		issorted(int *stack);
int		isonly_whitesp(char *str);
void	sa(int **a);
void	sb(int **b);
void	ss(int **a, int **b);
int		*pa(int **a, int **b);
int		*pb(int **a, int **b);
void	ra(int **a);
void	rb(int **b);
void	rr(int **a, int **b);
void	rra(int **a);
void	rrb(int **b);
void	rrr(int **a, int **b);
void	shit_sort(int **a, int **b, int len);
int		divide_stack(int **a, int **b);


void	print_stack(int *a); // - dont forget to delete this function

#endif