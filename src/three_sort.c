/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 14:39:44 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/11 15:52:59 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_2_3(t_stack **a)
{
	if ((*a)->arr[1] > (*a)->arr[2])
	{
		ft_printf("sa\n");
		ft_printf("rra\n");
		sa(a);
		rra(a);
	}
	else
	{
		ft_printf("ra\n");
		ra(a);
	}
}

void	three_sort(t_stack **a)
{
	if (issorted(*a))
		return ;
	if ((*a)->arr[0] > (*a)->arr[1] && (*a)->arr[0] < (*a)->arr[2])
	{
		ft_printf("sa\n");
		sa(a);
	}
	else if ((*a)->arr[0] > (*a)->arr[1] && (*a)->arr[0] > (*a)->arr[2])
		case_2_3(a);
	else if (((*a)->arr[0] < (*a)->arr[1] && (*a)->arr[0] < (*a)->arr[2]))
	{
		ft_printf("sa\n");
		ft_printf("ra\n");
		sa(a);
		ra(a);
	}
	else if ((*a)->arr[0] < (*a)->arr[1] && (*a)->arr[1] > (*a)->arr[2])
	{
		ft_printf("rra\n");
		rra(a);
	}
}
