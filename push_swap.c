/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:53:04 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/09 22:18:27 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	int		*a;
	int		*b;
	char	**str;

	if (argc > 1)
	{
		str = get_args(++argv);
		if (!str || !validation(str))
		{
			ft_printf("Error\n");
			ft_free_two_dim_arr(str);
			return (0);
		}
		a = get_intarr(str);
		// print_stack(a);
		// ft_printf("\n");
		ft_free_two_dim_arr(str);
		// if (!(b = (int *)ft_memalloc(sizeof(int) * (0))))
		// 	return (0);
		shit_sort(&a, &b);
		free(a);
		a = NULL;
	}
}
