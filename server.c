/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 00:34:21 by acanelas          #+#    #+#             */
/*   Updated: 2023/02/21 05:54:47 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	put_char(int sinal)
{
	static int	c;
	static int	bit;

	if (sinal == SIGUSR1)
		c |= 1 << bit;
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_handler = put_char;
	pid = getpid();
	(void)argv;
	if (argc != 1)
	{
		ft_printf("You should learn how to type...");
		ft_printf("Just type './server' -.-");
		return (0);
	}
	ft_printf("PID --> [%d]\n", pid);
	ft_printf("Getting the message, wait a sec...\n");
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
