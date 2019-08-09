/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intarr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:38:35 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/09 12:59:40 by vhazelnu         ###   ########.fr       */
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

int		get_min_value(char **str, int **stack, int **tmp, int i)
{
	int	min;

	if (!(*stack = (int *)ft_memalloc(sizeof(int) * (i + 1))))
		return (0);
	if (!(*tmp = (int *)malloc(sizeof(int) * (i + 1))))
		return (0);
	(*stack)[i] = '\0';
	(*tmp)[i] = '\0';
	min = find_min(str, i - 1);
	while (--i >= 0)
		(*tmp)[i] = -1;
	return (min);
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
	min = get_min_value(str, &stack, &tmp, i);
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
	free(tmp);
	tmp = NULL;
	return (stack);
}
