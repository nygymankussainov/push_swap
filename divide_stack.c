/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 22:10:41 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/11 12:50:29 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_stack(t_stack **a, t_stack **b)
{
	int	max;
	int	i;

	max = (*a)->size;
	i = 0;
	while (i < (*a)->size - 1)
	{
		if ((*a)->arr[0] < max)
		{
			pb(a, b);
			ft_printf("pb\n");
			i = 0;
		}
		else
		{
			ft_printf("ra\n");
			ra(a);
			i = 0;
		}
		i++;
	}
}
