/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shit_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:00:29 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/09 22:21:12 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_lowest_top(int **a)
{
	int	len;
	int	min;
	int	min_i;
	int	i;
	len = ft_intarrlen(*a);

	min = (*a)[0];
	i = 0;
	while ((*a)[i])
	{
		if ((*a)[i] < min)
		{
			min = (*a)[i];
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

void	only_two_a(int **a, int **b)
{
	int	max;
	int	i;

	max = ft_intarrlen(*a);
	i = 0;
	while ((*a)[i + 1])
	{
		if ((*a)[0] < max)
		{
			*b = pb(a, b);
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

void	do_instructions(int **a, int **b, int i)
{
	int closest;
	int	len_a;
	int	len_b;
	int	instr;

	closest = find_closest(*a, *b, i);
	len_a = ft_intarrlen(*a);
	len_b = ft_intarrlen(*b);
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
	if (closest + 1 > len_a / 2)
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
	*a = pa(a, b);
	ft_printf("pa\n");
	// ft_printf("a: \n");
	// print_stack(*a);
	// ft_printf("b: \n");
	// print_stack(*b);
}

void	shit_sort(int **a, int **b)
{
	int	i;

	only_two_a(a, b);
	// print_stack(*a);
	// ft_printf("\n");
	// print_stack(*b);
	while (**b)
	{
		i = find_best_case(*a, *b);
		do_instructions(a, b, i);
	}
	if (!issorted(*a))
		find_lowest_top(a);
	// print_stack(*a);
	// ft_printf("\n");
}
