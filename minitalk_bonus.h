/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:14:29 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/03/04 15:11:43 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

void	ft_print_pid(int pid);
void	ft_putchar(char c);
int		ft_atoi(char *str);
int		ft_store_byte(int c_byte, int b);

#endif