/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:39:24 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/03/01 17:25:50 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	ft_handler(int sig, siginfo_t *info, void *context)
{
	static int	pow;
	static int	nbr;
	static int	pid_c;
	int			bit;

	(void)context;
	if (pid_c == 0)
		pid_c = info->si_pid;
	if (pid_c != info->si_pid)
	{
		pid_c = info->si_pid;
		nbr = 0;
		pow = 0;
	}
	bit = 0;
	if (sig == SIGUSR1)
		bit = 1;
	else if (sig == SIGUSR2)
		bit = 0;
	if (bit)
		nbr += ft_power(2, pow);
	pow++;
	if (pow == 8)
		(ft_putchar(nbr), nbr = 0, pow = 0);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_print_pid(pid);
	ft_putchar('\n');
	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		return (write(2, "Error in sigaction()\n", 21), 1);
	while (1)
		pause();
	return (0);
}
