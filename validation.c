/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:26:41 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/05 21:25:08 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		isint_limit(char *str)
{
	size_t					i;
	long long 				result;
	int						sign;

	i = 0;
	result = 0;
	sign = 1;
	i = ft_skip_whitesp(str);
	if (str[i] == '-' || str[i] == '+')
	{
		sign = str[i] == '-' ? -1 : sign;
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + str[i] - '0';
		if ((result > 2147483647 && sign > 0) || (result > 2147483648 && sign < 0))
			return (0);
		i++;
	}
	return (1);
}

int		isint(char *str)
{
	int		i;
	int		sign;

	i = 0;
	i = str[i] == '-' || str[i] == '+' ? 1 : 0;
	sign = i == 1 ? 1 : 0;
	str += sign && str[1] ? 1 : 0;
	if (!str[i])
		return (0);
	if (str[0] == '0' && str[1])
		while (*str == '0')
			str++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if ((i > 10 && !sign) || (i + 1 > 11 && sign))
		return (0);
	if ((i == 10 && !sign) || (i + 1 == 11 && sign))
		return (isint_limit(str));
	return (1);
}

int		check_duplicate(char **str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
			if (!ft_strcmp(str[i], str[j++]))
				return (0);
		i++;
	}
	return (1);
}

int		validation(char **str)
{
	int					i;
	int					j;
	long long			nbr;

	i = 0;
	if (!str)
	{
		ft_printf("Error\n");
		return (0);
	}
	while (str[i])
	{
		if (!isint(str[i]))
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	if (!check_duplicate(str))
	{
		ft_printf("Error\n");
		return (0);
	}
	ft_printf("OK\n");
	return (1);
}
