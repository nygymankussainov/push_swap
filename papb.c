/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   papb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:10:46 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/10 16:33:36 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		get_copy(t_stack **c, t_stack **tmp)
{
	int		i;

	if (!(*tmp = (t_stack *)ft_memalloc(sizeof(t_stack))))
		return ;
	(*tmp)->size = (*c)->size;
	(*tmp)->last = (*c)->last;
	if (!((*tmp)->arr = (int *)malloc(sizeof(int) * (*tmp)->size)))
		return ;
	i = 0;
	while (i < (*tmp)->size)
	{
		(*tmp)->arr[i] = (*c)->arr[i];
		i++;
	}
	free((*c)->arr);
	free(*c);
	*c = NULL;
	if (!(*c = (t_stack *)ft_memalloc(sizeof(t_stack))))
		return ;
	(*c)->size = (*tmp)->size + 1;
	(*c)->last = (*tmp)->last + 1;
}

void		remove_top_elem(t_stack **c)
{
	t_stack	*tmp;
	int		i;

	if ((*c)->size == 1)
	{
		free((*c)->arr);
		free(*c);
		*c = NULL;
		return ;
	}
	else
		get_copy(c, &tmp);
	(*c)->size = tmp->size - 1;
	(*c)->last = tmp->last - 1;
	if (!((*c)->arr = (int *)malloc(sizeof(int) * (*c)->size)))
		return ;
	i = 0;
	while (i < (*c)->size)
	{
		(*c)->arr[i] = tmp->arr[i + 1];
		i++;
	}
	free(tmp->arr);
	free(tmp);
	tmp = NULL;
}

void		pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;
	int		isfree;

	isfree = 0;
	if ((*a)->size)
	{
		get_copy(a, &tmp);
		isfree = 1;
	}
	else
	{
		free(*a);
		if (!(*a = (t_stack *)ft_memalloc(sizeof(t_stack))))
			return ;
		(*a)->size = 1;
		(*a)->last = 1;
	}
	if (!((*a)->arr = (int *)malloc(sizeof(int) * (*a)->size)))
		return ;
	(*a)->arr[0] = (*b)->arr[0];
	i = 1;
	while (i < (*a)->size)
	{
		(*a)->arr[i] = tmp->arr[i - 1];
		i++;
	}
	if (isfree == 1)
	{
		free(tmp->arr);
		free(tmp);
		tmp = NULL;
	}
	remove_top_elem(b);
}

void		pb(t_stack **a, t_stack **b)
{
	pa(b, a);
}
