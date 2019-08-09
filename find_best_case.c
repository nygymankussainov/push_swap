/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 17:06:01 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/09 21:58:45 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_closest(int *a, int *b, int i)
{
	int closest;
	int	j;
	int diff;
	int	tmp;

	j = 0;
	closest = 0;
	diff = 2147483647;
	while (a[j])
	{
		// ft_printf("a[j]: %d\n", a[j]);
		// ft_printf("b[i]: %d\n", b[i]);
		tmp = a[j] - b[i];
		if (tmp < diff && tmp > 0)
		{
			diff = tmp;
			closest = j;
		}
		j++;
	}
	return (closest);
}

int		count_instr(int *a, int *b, int i)
{
	int closest;
	int	len_a;
	int	len_b;
	int	instr;

	closest = find_closest(a, b, i);
	len_a = ft_intarrlen(a);
	len_b = ft_intarrlen(b);
	instr = 0;
	if (i == 0)
		instr = 0;
	else if (i > len_b / 2)
		instr = len_b - i;
	else if (i < len_b / 2)
		instr = i;
	if (closest + 1 > len_a / 2)
		instr += len_a - closest;
	else if (closest + 1 < len_a / 2)
		instr += closest;
	return (++instr);
}

int		find_best_case(int *a, int *b)
{
	int i;
	int	instr;
	int	min;
	int	index;

	i = 0;
	min = 2147483647;
	while (b[i])
	{
		// ft_printf("b[i]: %d\n", b[i]);
		instr = count_instr(a, b, i);
		if (instr < min)
		{
			min = instr;
			index = i;
		}
		i++;
	}
	return (index);
}
