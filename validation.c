/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:26:41 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/06 13:21:13 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		isonly_whitesp(char *str)
{
	while (*str)
	{
		if (ft_isascii(*str) && *str != ' ' && *str != '\t')
			return (1);
		str++;
	}
	return (0);
}

int		isint_limit(char *str, int sign)
{
	size_t		i;
	long long	result;

	i = 0;
	result = 0;
	i = ft_skip_whitesp(str);
	if (str[i] == '-' || str[i] == '+')
	{
		sign = str[i] == '-' ? -1 : sign;
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + str[i] - '0';
		if ((result > 2147483647 && sign > 0) ||
			(result > 2147483648 && sign < 0))
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
	sign = (i == 1 && str[0] == '+') || !i ? 1 : -1;
	str += sign && str[1] && i ? 1 : 0;
	if (!str[i])
		return (0);
	if (str[0] == '0' && str[1])
		while (*str == '0' && *str)
			str++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i > 10)
		return (0);
	if (i == 10)
		return (isint_limit(str, sign));
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
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!isint(str[i]))
			return (0);
		i++;
	}
	if (!check_duplicate(str))
		return (0);
	return (1);
}
