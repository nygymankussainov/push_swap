/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:53:04 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/10/23 16:48:27 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap( t_stack **a, t_stack **b)
{
	if (issorted(*a))
	{
		free((*a)->arr);
		free(*a);
		*a = NULL;
		return ;
	}
	if ((*a)->size == 3)
		three_sort(a);
	else
	{
		if (!(*b = (t_stack *)ft_memalloc(sizeof(t_stack))))
			return ;
		if ((*a)->size == 5)
			five_sort(a, b);
		else
			shit_sort(a, b);
	}
	free((*a)->arr);
	free(*a);
	*a = NULL;
}

int		main(int argc, char **argv)
{
	int			i;
	t_stack		*a;
	t_stack		*b;
	char		**str;

	i = 0;
	if (argc > 1)
	{
		str = get_args(++argv);
		if (!str || !validation(str))
		{
			write(2, "Error\n", 6);
			ft_free_two_dim_arr(str);
			return (0);
		}
		while (str[i])
			i++;
		a = get_intarr(str);
		ft_free_two_dim_arr(str);
		push_swap(&a, &b);
	}
}
