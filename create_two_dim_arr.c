/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_two_dim_arr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 19:25:42 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/05 21:19:47 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**fill_twodim_arr(char **dst, char **src, int start, int end)
{
	int		i;

	i = 0;
	while (start < end)
	{
		dst[start] = ft_strdup(src[i]);
		i++;
		start++;
	}
	dst[start] = NULL;
	return (dst);
}

int		create_twodim_arr(char *str, char ***result)
{
	int		i;
	char	**tmp;
	
	i = 0;
	tmp = ft_strsplit(str, ' ', '\t');
	while (tmp[i])
		i++;
	if (!i)
	{
		ft_free_two_dim_arr(tmp);
		return (0);
	}
	if (!(*result = (char **)ft_memalloc(sizeof(char *) * (i + 1))))
		return (0);
	(*result)[i] = NULL;
	*result = fill_twodim_arr(*result, tmp, 0, i);
	ft_free_two_dim_arr(tmp);
	return (i);
}

char	**add_str_in_twodim_arr(char *str, char ***old, int len)
{
	char	**new;
	char	**tmp;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 1;
	tmp = NULL;
	if (ft_istabspace_in_str(str))
		j = create_twodim_arr(str, &tmp);
	if (!(new = (char **)ft_memalloc(sizeof(char *) * (len + j + 1))))
		return (NULL);
	new[len + j] = NULL;
	new = fill_twodim_arr(new, *old, 0, len);
	new = tmp ? fill_twodim_arr(new, tmp, len, len + j) : new;
	new[len] = !tmp ? ft_strdup(str) : new[len];
	if (tmp)
	{
		ft_free_two_dim_arr(tmp);
	}
	ft_free_two_dim_arr(*old);
	return (new);
}

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

int		get_args(char **str)
{
	int		i;
	int		j;
	char	**result;

	i = 0;
	j = 1;
	result = NULL;
	while (str[i])
	{
		if (!isonly_whitesp(str[i]))
		{
			if (result)
				ft_free_two_dim_arr(result);
			return (validation(NULL));
		}
		if (ft_istabspace_in_str(str[i]))
		{
			if (result)
				result = add_str_in_twodim_arr(str[i], &result, j++);
			else
				if (!(j = create_twodim_arr(str[i], &result)))
					break ;
		}
		else
		{
			if (result)
				result = add_str_in_twodim_arr(str[i], &result, j++);
			else
				if (!(j = create_twodim_arr(str[i], &result)))
					break ;

		}
		i++;
	}
	int d;
	d = 0;
	if (!validation(result))
	{
		if (j)
		{
			while (result[d])
			{
				ft_printf("%s\n", result[d]);
				d++;
			}
			ft_free_two_dim_arr(result);
		}
		return (0);
	}
	while (result[d])
	{
		ft_printf("%s\n", result[d]);
		d++;
	}
	ft_free_two_dim_arr(result);
	return (1);
}
