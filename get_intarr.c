/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intarr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:38:35 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/06 19:39:10 by vhazelnu         ###   ########.fr       */
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

int		*get_intarr(char **str)
{
	int		i;
	int		*stack;

	i = 0;
	while (str[i])
		i++;
	if (!(stack = (int *)ft_memalloc(sizeof(int) * (i + 1))))
		return (0);
	stack[i] = '\0';
	i = 0;
	while (str[i])
	{
		stack[i] = ft_atoi(str[i]);
		i++;
	}
	return (stack);
}
