/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 14:54:15 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/11 15:51:07 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_sort(t_stack **a, t_stack **b)
{
	find_lowest_top(a);
	if (issorted(*a))
	{
		free(*b);
		*b = NULL;
		return ;
	}
	pb(a, b);
	ft_printf("pb\n");
	find_lowest_top(a);
	pb(a, b);
	ft_printf("pb\n");
	three_sort(a);
	if ((*b)->arr[0] < (*b)->arr[1])
	{
		sb(b);
		ft_printf("sb\n");
	}
	pa(a, b);
	ft_printf("pa\n");
	pa(a, b);
	ft_printf("pa\n");
}
