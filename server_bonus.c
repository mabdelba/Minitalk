/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:23:48 by mabdelba          #+#    #+#             */
/*   Updated: 2022/02/27 23:11:25 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

// server_bonus

void	tap_char(int sig, int drp, int pid)
{
	static int	i;
	char		tab[9];
	char		c;

	(void)pid;
	if (sig == 0)
		c = '0';
	else
		c = '1';
	if (drp == 1)
		i = 0;
	tab[i] = c;
	i++;
	if (i == 8)
	{
		if (ft_strncmp(tab, "00000000", 8) == 0)
			kill(pid, SIGUSR2);
		else
		{
			binto_dec(tab);
			i = 0;
		}
	}
}

void	handler(int sig, siginfo_t *info, void *u)
{
	static int	id;
	int			drp;

	(void)u;
	drp = 0;
	if (id != info->si_pid)
	{
		drp = 1;
		id = info->si_pid;
	}
	if (sig == SIGUSR1)
		tap_char(0, drp, info->si_pid);
	if (sig == SIGUSR2)
		tap_char(1, drp, info->si_pid);
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.__sigaction_u.__sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_putstr("PID : ");
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		pause();
}
