/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:18:05 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/10 17:38:35 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		user_sort(t_stack **a, t_stack **b)
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
			pa(a, b);
		else if (!ft_strcmp("pb", line))
			pb(a, b);
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
			line = NULL;
			return (0);
		}
		free(line);
		line = NULL;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
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
		if (!(b = (t_stack *)ft_memalloc(sizeof(t_stack))))
			return (0);
		if (!user_sort(&a, &b))
		{
			ft_printf("Error\n");
			free(a->arr);
			free(a);
			a = NULL;
			return (0);
		}
		if (issorted(a))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free(a->arr);
		free(a);
		a = NULL;
	}
	return (0);
}
