/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 13:18:05 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/06 16:35:10 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		issorted(int *stack)
{
	int		i;
	int		j;

	i = 0;
	while (stack[i])
	{
		j = i + 1;
		if (stack[j] && stack[i] > stack[j])
			return (0);
		i++;
	}
	return (1);
}

int		*get_intarr(char **str)
{
	int		i;
	int		*stack;

	i = 0;
	while (str[i])
		i++;
	if (!(stack = (int *)ft_memalloc(sizeof(int) * (i + 1))))
		return (0);
	stack[i] = '\0';
	i = 0;
	while (str[i])
	{
		stack[i] = ft_atoi(str[i]);
		i++;
	}
	return (stack);
}

void	user_sort(int **a, int **b)
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
		free(line);
	}
}

int		main(int argc, char **argv)
{
	int		*a;
	int		*b;
	char	**str;

	b = (int *)ft_memalloc(sizeof(int) * 4);
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
		user_sort(&a, &b);
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
