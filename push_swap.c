/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:53:04 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/08 18:29:45 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	int		*a;
	// int		*b;
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
		ft_free_two_dim_arr(str);
		// a = shit_sort(&a, &b);
	}
}
