/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarrcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 21:54:14 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/07 11:52:31 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_intarrcat(int **a, int **b)
{
	int		*stack;
	int		len;
	int		i;
	int		j;

	len = ft_intarrlen(*a) + ft_intarrlen(*b);
	if (!(stack = (int *)ft_memalloc(sizeof(int) * (len + 1))))
		return (0);
	stack[len] = '\0';
	i = 0;
	while ((*a)[i])
	{
		stack[i] = (*a)[i];
		i++;
	}
	j = 0;
	while ((*b)[j])
	{
		stack[i] = (*b)[j];
		i++;
		j++;
	}
	free(*a);
	*a = NULL;
	free(*b);
	*b = NULL;
	return (stack);
}
