/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intarr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:38:35 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/08 21:52:04 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		isonly_whitesp(char *str)
{
	while (*str)
	{
		if (ft_isascii(*str) && *str != ' ' && *str != '\t')
			return (1);
		str++;
	}
	return (0);
}

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
				(*tmp)[i - 1] = -1;
			key = 1;
			(*tmp)[i] = i + 1;
			min_i = i;
			mintmp = ft_atoi((*str)[i]);
		}
		i++;
	}
	if (!key)
	{
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
	return (min_i);
}

int		find_min(char **str, int i)
{
	int	min;
	int	tmp;
	int	j;

	j = 0;
	min = ft_atoi(str[0]);
	while (j < i)
	{
		tmp = ft_atoi(str[j]);
		if (tmp < min)
			min = tmp;
		j++;
	}
	return (min);
}

int		istmpfull(int *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == -1)
			return (0);
		i++;
	}
	return (1);
}

int		*get_intarr(char **str)
{
	int		i;
	int		min_i;
	int		min;
	int		*tmp;
	int		*stack;

	i = 0;
	while (str[i])
		i++;
	if (!(stack = (int *)ft_memalloc(sizeof(int) * (i + 1))))
		return (0);
	if (!(tmp = (int *)malloc(sizeof(int) * (i + 1))))
		return (0);
	stack[i] = '\0';
	tmp[i] = '\0';
	min = find_min(str, i - 1);
	while (--i >= 0)
		tmp[i] = -1;
	i = 0;
	min_i = 0;
	while (str[i])
	{
		min_i = arr_indexation(&str, &min, min_i, &tmp);
		stack[min_i] = i + 1;
		if (istmpfull(tmp))
			break ;
		i++;
	}
	print_stack(stack);
	return (stack);
}
