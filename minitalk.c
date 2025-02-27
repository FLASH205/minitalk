/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:13:51 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/27 14:07:47 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void  handler(int signal)  
{
  if (signal == SIGUSR1)
    	write(1, "blah\n", 5);
}

int main(int argc , char *argv[])
{
	int pid = getpid();

	printf("%d\n", pid);
	signal(SIGUSR1, handler);
	while (1)
		pause();
 return (0);
}
