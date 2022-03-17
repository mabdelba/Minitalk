/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:50:07 by mabdelba          #+#    #+#             */
/*   Updated: 2022/02/27 23:03:11 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr(char *str);
void	binto_dec(char *str);
int		ft_atoi(const char	*str);
void	ft_putnbr(int nb);
#endif // MINITALK_BONUS_H
