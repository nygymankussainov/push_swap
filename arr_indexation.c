/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_indexation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 12:58:07 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/09 12:59:30 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_index(int *tmp, int i)
{
	int		j;

	j = 0;
	while (tmp[j])
	{
		if (tmp[j] == i)
			return (1);
		j++;
	}
	return (0);
}

int		ifnokey(char ***str, int *min, int **tmp)
{
	int	key;
	int	i;

	key = 0;
	while (ft_atoi((*str)[key]) != *min)
		key++;
	i = key + 1;
	while ((*tmp)[i] && (*tmp)[i] != -1)
		i++;
	(*tmp)[key] = key + 1;
	if ((*str)[i])
		*min = ft_atoi((*str)[i]);
	else
	{
		i = 0;
		while ((*tmp)[i] && (*tmp)[i] != -1)
			i++;
		if ((*str)[i])
			*min = ft_atoi((*str)[i]);
	}
	return (key);
}

void	ifkey(char ***str, int **tmp, int mintmp)
{
	int	key;

	key = 0;
	while (ft_atoi((*str)[key]) != mintmp)
		key++;
	(*tmp)[key] = -1;
}

int		arr_indexation(char ***str, int *min, int min_i, int **tmp)
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
			(*tmp)[i] = i + 1;
			min_i = i;
			mintmp = ft_atoi((*str)[i]);
		}
		i++;
	}
	if (!key)
		return (ifnokey(str, min, tmp));
	return (min_i);
}
