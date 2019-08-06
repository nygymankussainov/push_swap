/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:10:32 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/06 15:54:11 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int **a)
{
	ft_swap(&(*a)[0], &(*a)[1]);
}

void	sb(int **b)
{
	sa(b);
}

void	ss(int **a, int **b)
{
	sa(a);
	sb(b);
}

int		*pa(int **a, int **b)
{
	int	*res;
	int	i;
	int	j;

	i = 0;
	if (*b)
	{
		while ((*a)[i])
			i++;
		if (!(res = (int *)ft_memalloc(sizeof(int) * (++i + 1))))
			return (0);
		res[i] = '\0';
		res[0] = (*b)[0];
		j = 1;
		while (j < i)
		{
			res[j] = (*a)[j - 1];
			j++;
		}
		free(*a);
		*a = NULL;
		return (res);
	}
	else
		return (*a); // - add statement if b is empty
}

int		*pb(int **a, int **b)
{
	return (pa(b, a));
}
