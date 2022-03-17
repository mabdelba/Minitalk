# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabdelba <mabdelba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 00:39:44 by mabdelba          #+#    #+#              #
#    Updated: 2022/02/27 20:22:46 by mabdelba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = server
NAME_2 = client
NAME_BNS = server_bonus
NAME_BNS_2 = client_bonus
C = gcc
F = -Wall -Wextra -Werror
CLI = client.c ft_atoi.c
SRV = server.c binto_dec.c ft_putstr.c ft_putnbr.c
CLI_BNS = client_bonus.c ft_atoi_bonus.c
SRV_BNS = server_bonus.c ft_strncmp_bonus.c binto_dec_bonus.c \
		ft_putstr_bonus.c  ft_putnbr_bonus.c
CLI_BNS_OBJ = $(CLI_BNS:.c=.o)
SRV_BNS_OBJ = $(SRV_BNS:.c=.o)
CLI_OBJ = $(CLI:.c=.o)
SRV_OBJ = $(SRV:.c=.o)

all: $(NAME) $(NAME_2)

%.o: %.c
	$(C) $(F) -c $<

$(NAME): $(SRV_OBJ)
	$(C) $(F) $(SRV_OBJ) -o $(NAME)

$(NAME_2): $(CLI_OBJ)
	$(C) $(F) $(CLI_OBJ) -o $(NAME_2)

bonus: $(NAME_BNS) $(NAME_BNS_2)

$(NAME_BNS): $(SRV_BNS_OBJ)
	$(C) $(F) $(SRV_BNS_OBJ) -o $(NAME_BNS)

$(NAME_BNS_2): $(CLI_BNS_OBJ)
	$(C) $(F) $(CLI_BNS_OBJ) -o $(NAME_BNS_2)

clean:
	rm -rf $(CLI_OBJ) $(SRV_OBJ) $(CLI_BNS_OBJ) $(SRV_BNS_OBJ)

fclean: clean
	rm -f $(NAME) $(NAME_2) $(NAME_BNS_2) $(NAME_BNS)

re: fclean all	