/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:18:05 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/11 14:49:29 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pick_instr(t_stack **a, t_stack **b, char *line)
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
		return (0);
	return (1);
}

int		user_sort(t_stack **a, t_stack **b)
{
	char *line;

	while (get_next_line(0, &line) == 1)
	{
		if (!pick_instr(a, b, line))
		{
			free(*b);
			*b = NULL;
			free(line);
			line = NULL;
			return (0);
		}
		free(line);
		line = NULL;
	}
	free(*b);
	*b = NULL;
	return (1);
}

void	checker(char **str)
{
	t_stack		*a;
	t_stack		*b;

	a = get_intarr(str);
	ft_free_two_dim_arr(str);
	if (!(b = (t_stack *)ft_memalloc(sizeof(t_stack))))
		return ;
	if (!user_sort(&a, &b))
	{
		write(2, "Error\n", 6);
		free(a->arr);
		free(a);
		a = NULL;
		return ;
	}
	if (issorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
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
		checker(str);
	}
	return (0);
}
