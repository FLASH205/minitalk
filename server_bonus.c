/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:39:24 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/03/04 14:54:45 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_power(int n, int pow)
{
	int	i;

	i = 1;
	if (pow == 0)
		return (1);
	while (i < pow)
	{
		n *= 2;
		i++;
	}
	return (n);
}

int	ft_check_sig(int sig)
{
	int	bit;

	bit = 0;
	if (sig == SIGUSR1)
		bit = 1;
	else if (sig == SIGUSR2)
		bit = 0;
	return (bit);
}

void	ft_check_byte(int nbr)
{
	if (nbr < 195)
		ft_store_byte(1, nbr);
	else if (nbr < 224)
		ft_store_byte(2, nbr);
	else if (nbr < 240)
		ft_store_byte(3, nbr);
	else
		ft_store_byte(4, nbr);
}

void	ft_handler(int sig, siginfo_t *info, void *context)
{
	int			bit;
	static int	pow;
	static int	nbr;
	static int	pid_c;

	(void)context;
	if (pid_c == 0)
		pid_c = info->si_pid;
	if (pid_c != info->si_pid)
		(ft_store_byte(-1, 0), pid_c = info->si_pid, nbr = 0, pow = 0);
	bit = ft_check_sig(sig);
	if (bit)
		nbr += ft_power(2, pow);
	pow++;
	if (pow == 8)
	{
		if (nbr == '\0')
		{
			if (kill(pid_c, SIGUSR1) == -1)
				(write(2, "Error in kill()\n", 16), exit(1));
		}
		(ft_check_byte(nbr), nbr = 0, pow = 0);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_print_pid(pid);
	ft_putchar('\n');
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		return (write(2, "Error in sigaction()\n", 21), 1);
	while (1)
		pause();
	return (0);
}
