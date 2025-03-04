/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_byte_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:53:27 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/03/04 14:53:47 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_store_byte(int c_byte, int b)
{
	static int				c;
	static unsigned char	arr[4];
	static int				index;

	if (c_byte == -1)
		return (index = 0, c = 0, arr[0] = 0,
			arr[1] = 0, arr[2] = 0, arr[3] = 0, 1);
	if (c == 0)
		c = c_byte;
	arr[index] = b;
	index++;
	if (c == index)
	{
		write(1, arr, c);
		index = 0;
		c = 0;
		arr[0] = 0;
		arr[1] = 0;
		arr[2] = 0;
		arr[3] = 0;
	}
	return (1);
}
