/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shit_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:00:29 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/10 19:00:29 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_lowest_top(t_stack **a)
{
	int	len;
	int	min;
	int	min_i;
	int	i;

	len = (*a)->size;
	min = (*a)->arr[0];
	i = 0;
	while (i < (*a)->size)
	{
		if ((*a)->arr[i] < min)
		{
			min = (*a)->arr[i];
			min_i = i;
		}
		i++;
	}
	if (min_i > len / 2)
	{
		i = len - min_i;
		while (i--)
		{
			ft_printf("rra\n");
			rra(a);
		}
	}
	else
	{
		while (min_i--)
		{
			ft_printf("ra\n");
			ra(a);
		}
	}
}

void	only_two_a(t_stack **a, t_stack **b)
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

void	do_instructions(t_stack **a, t_stack **b, int i)
{
	int closest;
	int	len_a;
	int	len_b;
	int	instr;

	closest = find_closest(*a, *b, i);
	len_a = (*a)->size;
	len_b = (*b)->size;
	instr = 0;
	if (i > 0)
	{
		if (i > len_b / 2)
		{
			instr = len_b - i;
			while (instr--)
			{
				ft_printf("rrb\n");
				rrb(b);
			}
		}
		else
		{
			instr = i;
			while (instr--)
			{
				ft_printf("rb\n");
				rb(b);
			}
		}
	}
	if (closest > len_a / 2)
	{
		instr = len_a - closest;
		while (instr--)
		{
			ft_printf("rra\n");
			rra(a);
		}
	}
	else
	{
		instr = closest;
		while (instr--)
		{
			ft_printf("ra\n");
			ra(a);
		}
	}
	pa(a, b);
	ft_printf("pa\n");
}

void	shit_sort(t_stack **a, t_stack **b)
{
	int	i;

	only_two_a(a, b);
	// print_stack(*a);
	// ft_printf("\n");
	// print_stack(*b);
	while (*b)
	{
		i = find_best_case(*a, *b);
		do_instructions(a, b, i);
	}
	if (!issorted(*a))
		find_lowest_top(a);
}
