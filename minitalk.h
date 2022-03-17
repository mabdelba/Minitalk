/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:58:31 by mabdelba          #+#    #+#             */
/*   Updated: 2022/02/27 23:05:19 by mabdelba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr(char *str);
void	binto_dec(char *str);
int		ft_atoi(const char	*str);
void	ft_putnbr(int nb);
#endif // MINITALK_H
