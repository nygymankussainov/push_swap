/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:18:05 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/06 19:40:00 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		user_sort(int **a, int **b)
{
	char *line;
	
	while (get_next_line(0, &line) == 1)
	{
		if (!ft_strcmp("sa", line))
			sa(a);
		else if (!ft_strcmp("sb", line))
			sb(b);
		else if (!ft_strcmp("ss", line))
			ss(a, b);
		else if (!ft_strcmp("pa", line))
			*a = pa(a, b);
		else if (!ft_strcmp("pb", line))
			*b = pb(a, b);
		else if (!ft_strcmp("ra", line))
			ra(a);
		else if (!ft_strcmp("rb", line))
			rb(b);
		else if (!ft_strcmp("rr", line))
			rr(a, b);
		else if (!ft_strcmp("rra", line))
			rra(a);
		else if (!ft_strcmp("rrb", line))
			rrb(b);
		else if (!ft_strcmp("rrr", line))
			rrr(a, b);
		else
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
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
		ft_free_two_dim_arr(str);
		i = ft_intarrlen(a);
		if (!(b = (int *)ft_memalloc(sizeof(int) * (i + 1))))
			return (0);
		b[0] = 4;
		b[1] = 5;
		b[2] = 6;
		b[i] = '\0';
		if (!user_sort(&a, &b))
		{
			ft_printf("Error\n");
			free(b);
			b = NULL;
			free(a);
			a = NULL;
			return (0);
		}
		i = 0;
		// while (a[i])
		// {
		// 	ft_printf("%d\n", a[i]);
		// 	i++;
		// }
		i = 0;
		ft_printf("\n");
		// while (b[i])
		// {
		// 	ft_printf("%d\n", b[i]);
		// 	i++;
		// }
		free(b);
		b = NULL;
		if (issorted(a) && !b)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free(a);
		a = NULL;
	}
	return (0);
}
