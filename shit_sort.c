/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shit_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:00:29 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/11 13:57:59 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_min_index(t_stack *a)
{
	int	min;
	int	min_i;
	int	i;

	min = a->arr[0];
	i = 0;
	while (i < a->size)
	{
		if (a->arr[i] < min)
		{
			min = a->arr[i];
			min_i = i;
		}
		i++;
	}
	return (min_i);
}

void	find_lowest_top(t_stack **a)
{
	int	min_i;
	int	i;

	min_i = find_min_index(*a);
	if (min_i > (*a)->size / 2)
	{
		i = (*a)->size - min_i;
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

void	instr_b(t_stack **b, int i)
{
	int	instr;

	instr = 0;
	if (i > 0)
	{
		if (i > (*b)->size / 2)
		{
			instr = (*b)->size - i;
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
}

void	do_instructions(t_stack **a, t_stack **b, int i)
{
	int closest;
	int	instr;

	closest = find_closest(*a, *b, i);
	instr_b(b, i);
	if (closest > (*a)->size / 2)
	{
		instr = (*a)->size - closest;
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

	divide_stack(a, b);
	if (issorted(*a) && !(*b)->arr)
	{
		free(*b);
		*b = NULL;
		return ;
	}
	while (*b)
	{
		i = find_best_case(*a, *b);
		do_instructions(a, b, i);
	}
	if (!issorted(*a))
		find_lowest_top(a);
}
