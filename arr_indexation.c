/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_indexation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 12:58:07 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/10 14:35:05 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_index(t_stack *tmp, int i)
{
	int		j;

	j = 0;
	while (j < tmp->size)
	{
		if (tmp->arr[j] == i)
			return (1);
		j++;
	}
	return (0);
}

int		ifnokey(char ***str, int *min, t_stack **tmp)
{
	int	key;
	int	i;

	key = 0;
	while (ft_atoi((*str)[key]) != *min)
		key++;
	i = key + 1;
	while (i < (*tmp)->size && (*tmp)->arr[i] != -1)
		i++;
	(*tmp)->arr[key] = key + 1;
	if ((*str)[i])
		*min = ft_atoi((*str)[i]);
	else
	{
		i = 0;
		while (i < (*tmp)->size && (*tmp)->arr[i] != -1)
			i++;
		if ((*str)[i])
			*min = ft_atoi((*str)[i]);
	}
	return (key);
}

void	ifkey(char ***str, t_stack **tmp, int mintmp)
{
	int	key;

	key = 0;
	while (ft_atoi((*str)[key]) != mintmp)
		key++;
	(*tmp)->arr[key] = -1;
}

int		arr_indexation(char ***str, int *min, int min_i, t_stack **tmp)
{
	int		mintmp;
	int		i;
	int		key;

	i = 0;
	key = 0;
	mintmp = *min;
	while ((*str)[i])
	{
		if (!find_index(*tmp, i + 1) && ft_atoi((*str)[i]) < mintmp)
		{
			if (key == 1)
				ifkey(str, tmp, mintmp);
			key = 1;
			(*tmp)->arr[i] = i + 1;
			min_i = i;
			mintmp = ft_atoi((*str)[i]);
		}
		i++;
	}
	if (!key)
		return (ifnokey(str, min, tmp));
	return (min_i);
}
