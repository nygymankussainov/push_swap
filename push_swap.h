/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:26:58 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/06 15:30:04 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf/ft_printf.h"

char	**get_args(char **str);
int		validation(char **str);
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

#endif
