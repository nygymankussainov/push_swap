/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhazelnu <vhazelnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:10:32 by vhazelnu          #+#    #+#             */
/*   Updated: 2019/08/06 17:11:30 by vhazelnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int **a)
{
	ft_swap(&(*a)[0], &(*a)[1]);
}

void	sb(int **b)
{
	sa(b);
}

void	ss(int **a, int **b)
{
	sa(a);
	sb(b);
}