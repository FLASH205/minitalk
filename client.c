/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:45:46 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/28 13:31:22 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int i;
	int j;
	int r;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+')
		i++;
	j = i;
	while (str[j])
	{
		if (!(str[j] >= '0' && str[j] <= '9'))
			return (-1);
		j++;
	}
	r = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		if (r > 2147483647)
			return (-1);
		i++;
	}
	return (r);
}

void	ft_send_data(char c, int pid)
{
	int	i;
	int	bit;

	i = 0;
	while (i < 8)
	{
		bit = c % 2;
		if (bit)
		{
			if (kill(pid, SIGUSR1) == -1)
				(write(2, "Error in kill()\n", 16), exit(1));
		}
		else
		{	
			if (kill(pid, SIGUSR2) == -1)
				(write(2, "Error in kill()\n", 16), exit(1));
		}
		usleep(200);
		c = c / 2;
		i++;
	}
}

int main(int argc, char *argv[])
{
	int		pid;
	int		i;

	if (argc != 3)
		return (write(2, "Should be two arguments\n", 24), 1);
	pid = ft_atoi(argv[1]);
	if (pid == -1)
		return (write(2, "Invalid PID\n", 12), 1);
	i = 0;
	while (argv[2][i])
	{
		ft_send_data(argv[2][i], pid);
		i++;
	}
	return (0);
}
