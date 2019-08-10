/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:20:05 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/10 17:25:39 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	int	i;
	int	j;

	j = 0;
	i = (*a)->size;
	while (j < --i)
	{
		ft_swap(&(*a)->arr[i - 1], &(*a)->arr[i]);
	}
}

void	rrb(t_stack **b)
{
	rra(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
