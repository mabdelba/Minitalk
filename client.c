/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:28:03 by mabdelba          #+#    #+#             */
/*   Updated: 2022/02/28 18:20:57 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//client

void	send(int pid, char *c)
{
	int	i;
	int	j;
	int	d;

	j = 0;
	while (c[j])
	{
		i = 0;
		while (i < 8)
		{
			d = 128 & c[j];
			if (d == 0)
			{
				if (kill(pid, SIGUSR1) < 0)
					(fprintf(stderr, "kill failed to send signal!\n"), exit(1));
			}
			else
			{
				if (kill(pid, SIGUSR2) < 0)
					(fprintf(stderr, "kill failed to send signal!\n"), exit(1));
			}
			usleep(300);
			c[j] = c[j] << 1;
			i++;
		}
		j++;
	}
}

int	main(int ac, char **av)
{	
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid < 0)
			exit(EXIT_FAILURE);
		send(pid, av[2]);
	}
	else
		write(1, "Error Arguments", 15);
	return (EXIT_SUCCESS);
}
