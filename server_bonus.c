/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:15:55 by acanelas          #+#    #+#             */
/*   Updated: 2023/02/21 05:56:46 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	put_char(int sinal, siginfo_t *info, void *ucontext)
{
	static int	c;
	static int	bit;

	(void)info;
	(void)ucontext;
	if (sinal == SIGUSR1)
		c |= 1 << bit;
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_sigaction = put_char;
	sa.sa_flags = SA_SIGINFO;
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
		pause ();
	}
	return (0);
}
