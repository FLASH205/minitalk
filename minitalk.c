/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:13:51 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/28 11:04:28 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_power(int n, int pow)
{
	int i = 1;
	while (i < pow)
	{
		n *= 2;
		i++;
	}
	return (n);
}

int main()
{
	printf("%d\n", ft_power(2, 7));
	return (0);
}
