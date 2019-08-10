/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:53:04 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/10 17:38:56 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		**str;
	int i;

	i = 0;
	if (argc > 1)
	{
		str = get_args(++argv);
		if (!str || !validation(str))
		{
			ft_printf("Error\n");
			ft_free_two_dim_arr(str);
			return (0);
		}
		while (str[i])
			i++;
		a = get_intarr(str);
		ft_free_two_dim_arr(str);
		if (!(b = (t_stack *)ft_memalloc(sizeof(t_stack))))
			return (0);
		shit_sort(&a, &b);
		free(a->arr);
		free(a);
		a = NULL;
	}
}
