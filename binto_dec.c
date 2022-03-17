/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binto_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:03:25 by mabdelba          #+#    #+#             */
/*   Updated: 2022/02/27 21:48:55 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_power(int nb, int power)
{
	int	i;
	int	puiss;

	i = 0;
	puiss = 1;
	if (power < 0)
		return (0);
	else if (nb == 0 && power == 0)
		return (1);
	else
	{
		while (i < power)
		{
			puiss = puiss * nb;
			i++;
		}
	}
	return (puiss);
}

void	binto_dec(char *str)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	j = 7;
	while (str[i] && j >= 0)
	{
		res = res + (str[i] - '0') * ft_power(2, j);
		i++;
		j--;
	}
	write(1, &res, 1);
}
