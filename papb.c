/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   papb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:10:46 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/09 21:09:31 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*remove_top_elem(int **a)
{
	int	*res;
	int	len;
	int	i;

	len = ft_intarrlen(*a);
	if (!(res = (int *)ft_memalloc(sizeof(int) * len)))
		return (0);
	res[len] = '\0';
	i = 1;
	while (i < len)
	{
		res[i - 1] = (*a)[i];
		i++;
	}
	return (res);
}

int		*pa(int **a, int **b)
{
	int	*res;
	int	i;
	int	j;

	i = 0;
	if (**b)
	{
		if (*a)
		{
			while ((*a)[i])
				i++;
		}
		if (!(res = (int *)ft_memalloc(sizeof(int) * (++i + 1))))
			return (0);
		res[i] = '\0';
		res[0] = (*b)[0];
		*b = remove_top_elem(b);
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
