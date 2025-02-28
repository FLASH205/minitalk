/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 09:39:24 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/28 16:48:40 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_pid(int pid)
{
	if (pid >= 0 && pid <= 9)
		ft_putchar(pid + '0');
	else if (pid >= 10)
	{
		ft_print_pid(pid / 10);
		ft_putchar(pid % 10 + '0');
	}
}

int	ft_power(int n, int pow)
{
	int i = 1;

	if (pow == 0)
		return 1;
	while (i < pow)
	{
		n *= 2;
		i++;
	}
	return (n);
}

void	ft_handler(int sig)
{
	static int	pow;
	static int	nbr;
	int			bit;

	bit = 0;
	if (sig == SIGUSR1)
		bit = 1;
	else if (sig == SIGUSR2)
		bit = 0;
	if (bit)
		nbr += ft_power(2, pow);
	pow++;
	if (pow == 8)
	{
		ft_putchar(nbr);
		nbr = 0;
		pow = 0;
	}
}

int main(void)
{
	int					pid;
	struct sigaction	sa;

	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	pid = getpid();
	ft_print_pid(pid);
	ft_putchar('\n');
	while (1)
		pause();
	return (0);
}
