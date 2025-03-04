/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:55:41 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/03/01 13:56:14 by ybahmaz          ###   ########.fr       */
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
