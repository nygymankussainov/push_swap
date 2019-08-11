/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 17:06:01 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/11 18:16:52 by vhazelnu         ###   ########.fr       */
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
	int	instr;

	closest = find_closest(a, b, i);
	instr = 0;
	if (i == 0)
		instr = 0;
	else if (i >= b->size / 2)
		instr = b->size - i;
	else if (i < b->size / 2)
		instr = i;
	if (closest > a->size / 2)
		instr += a->size - closest;
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
