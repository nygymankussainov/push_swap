/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 22:10:41 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/06 22:25:45 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		divide_stack(int **a, int **b)
{
	int		i;
	int		j;
	int		k;
	int		len;
	int		*stack;

	i = 0;
	len = ft_intarrlen(*a);
	if (!(*b = (int *)ft_memalloc(sizeof(int) * (len / 2 + 1))))
		return (0);
	(*b)[len / 2] = '\0';
	if (!(stack = (int *)ft_memalloc(sizeof(int) * (len + 1))))
		return (0);
	stack[len] = '\0';
	while (i < len)
	{
		stack[i] = (*a)[i];
		i++;
	}
	free(*a);
	*a = NULL;
	if (!(*a = (int *)ft_memalloc(sizeof(int) * (len / 2 + 1))))
		return (0);
	(*a)[len / 2] = '\0';
	i = 0;
	k = 0;
	while (stack[i])
	{
		j = i + 1;
		if (stack[j] && stack[i] > stack[j])
		{
			(*b)[k] = stack[i];
			(*a)[k] = stack[j];
		}
		else if (stack[j] && stack[i] < stack[j])
		{
			(*a)[k] = stack[i];
			(*b)[k] = stack[j];
		}
		k++;
		i += 2;
	}
	free(stack);
	stack = NULL;
	// ft_printf("a before: \n");
	// print_stack(*a);
	// ft_printf("\nb before: \n");
	// print_stack(*b);
	return (len / 2);
}
