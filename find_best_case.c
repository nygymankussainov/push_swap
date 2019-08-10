/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 17:06:01 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/10 19:00:18 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_closest(t_stack *a, t_stack *b, int i)
{
	int closest;
	int	j;
	int diff;
	int	tmp;

	j = 0;
	closest = 0;
	diff = 2147483647;
	while (j < a->size)
	{
		tmp = a->arr[j] - b->arr[i];
		if (tmp < diff && tmp > 0)
		{
			diff = tmp;
			closest = j;
		}
		j++;
	}
	return (closest);
}

int		count_instr(t_stack *a, t_stack *b, int i)
{
	int closest;
	int	len_a;
	int	len_b;
	int	instr;

	closest = find_closest(a, b, i);
	len_a = a->size;
	len_b = b->size;
	instr = 0;
	if (i == 0)
		instr = 0;
	else if (i >= len_b / 2)
		instr = len_b - i;
	else if (i < len_b / 2)
		instr = i;
	if (closest > len_a / 2)
		instr += len_a - closest;
	else
		instr += closest;
	return (++instr);
}

int		find_best_case(t_stack *a, t_stack *b)
{
	int i;
	int	instr;
	int	min;
	int	index;

	i = 0;
	min = 2147483647;
	while (i < b->size)
	{
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
