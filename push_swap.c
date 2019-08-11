/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:53:04 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/11 13:52:18 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char **str)
{
	t_stack		*a;
	t_stack		*b;
	int			i;

	i = 0;
	while (str[i])
		i++;
	a = get_intarr(str);
	if (issorted(a))
	{
		free(a->arr);
		free(a);
		a = NULL;
		return ;
	}
	ft_free_two_dim_arr(str);
	if (!(b = (t_stack *)ft_memalloc(sizeof(t_stack))))
		return ;
	shit_sort(&a, &b);
	free(a->arr);
	free(a);
	a = NULL;
}

int		main(int argc, char **argv)
{
	char		**str;

	if (argc > 1)
	{
		str = get_args(++argv);
		if (!str || !validation(str))
		{
			write(2, "Error\n", 6);
			ft_free_two_dim_arr(str);
			return (0);
		}
		push_swap(str);
	}
}
