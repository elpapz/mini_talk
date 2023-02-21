/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:15:38 by acanelas          #+#    #+#             */
/*   Updated: 2023/02/21 05:58:54 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	send_sig(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else if ((c & (1 << bit)) == 0)
			kill(pid, SIGUSR2);
		usleep(50000);
		bit++;
	}
}

static void	confirm_delivery(int sinal)
{
	if (sinal == SIGUSR1)
		ft_printf("message recived brov!! \n");
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;
	int					i;

	sa.sa_handler = &confirm_delivery;
	i = 0;
	pid = ft_atoi(argv[1]);
	if (argc != 3)
	{
		ft_printf("Your input is wrong, get your s*** together");
		ft_printf("Plese try: ./client [PID] [message to be send]");
		return (0);
	}
	while (argv[2][i])
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		send_sig(argv[2][i], pid);
		i++;
	}
	return (0);
}
