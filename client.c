/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 00:34:33 by acanelas          #+#    #+#             */
/*   Updated: 2023/02/21 05:58:26 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		usleep(750);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	pid = ft_atoi(argv[1]);
	if (argc != 3)
	{
		ft_printf("Your input is wrong, get your s*** together!!!\n");
		ft_printf("Plese try: ./client [PID] [message to be send]\n");
		return (0);
	}
	while (argv[2][i])
	{
		send_sig(argv[2][i], pid);
		i++;
	}
	return (0);
}
