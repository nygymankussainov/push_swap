/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shit_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:00:29 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/06 22:56:33 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_lowest_top(int **ab, int len, char c)
{
	while ((*ab)[0] > (*ab)[1] || (*ab)[0] > (*ab)[len - 1])
	{
		if ((*ab)[0] > (*ab)[len - 1])
		{
			ft_printf("r%c\n", c);
			ra(ab);
		}
		else if ((*ab)[0] > (*ab)[1])
		{
			ft_printf("s%c\n", c);
			sa(ab);
		}
	}
}

void	shit_sort(int **a, int **b, int len)
{
	find_lowest_top(a, len, 'b');
	find_lowest_top(b, len, 'a');
	*a = ft_intarrcat(a, b);
	ft_printf("\n\n");
	ft_printf("A : \n");
	print_stack(*a);
	if (issorted(*a))
		return ;
	divide_stack(a, b);
	ft_printf("\n\n");
	ft_printf("a after: \n");
	print_stack(*a);
	ft_printf("\nb after: \n");
	print_stack(*b);
	while (b != NULL)
	{
		if ((a[0] < b[0]) && (b[0] < a[1]))
		{
			*a = pa(a, b);
			sa(a);
			print_stack(*a);
			print_stack(*b);
		}
		else
			ra(a);
	}
	free(*a);
	free(*b);
	*a = NULL;
	*b = NULL;
}
