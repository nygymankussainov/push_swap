/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shit_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:00:29 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/08 18:32:54 by vhazelnu         ###   ########.fr       */
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

int		*shit_sort(int **a, int **b, int len)
{
	*a = 0;
	*b = 0;
	len = 0;
	return (0);
}
