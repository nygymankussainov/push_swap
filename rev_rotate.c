/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:20:05 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/06 15:27:13 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(int **a)
{
	int	i;
	int	j;

	i = 0;
	while ((*a)[i])
		i++;
	j = 0;
	while (j < --i)
	{
		ft_swap(&(*a)[i - 1], &(*a)[i]);
	}
}

void	rrb(int **b)
{
	rra(b);
}

void	rrr(int **a, int **b)
{
	rra(a);
	rrb(b);
}
