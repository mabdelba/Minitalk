/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 23:28:03 by mabdelba          #+#    #+#             */
/*   Updated: 2022/02/27 22:37:39 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

//client_bonus
void	ft_kill(int pid, int sig)
{
	kill(pid, sig);
	usleep(300);
}

void	send(int pid, char *c)
{
	int	i;
	int	j;
	int	d;

	j = 0;
	while (c[j])
	{
		i = -1;
		while (++i < 8)
		{
			d = 128 & c[j];
			if (d == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(300);
			c[j] = c[j] << 1;
		}
		j++;
	}
	i = -1;
	while (++i < 8)
		ft_kill(pid, SIGUSR1);
}

void	handle(int sig)
{
	(void)sig;
	write(1, "it's okey !\n", 12);
}

int	main(int ac, char **av)
{	
	int	pid;

	signal(SIGUSR2, handle);
	usleep(300);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid == -1)
			exit(0);
		send(pid, av[2]);
	}
	else
		write(1, "Error Arguments", 15);
	return (0);
}
