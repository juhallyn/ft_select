/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 15:56:45 by juhallyn          #+#    #+#             */
/*   Updated: 2017/10/26 18:40:30 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_signal(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGWINCH, signal_handler);
}

void		signal_handler(int sig)
{
	if (sig == SIGINT)
		ft_exit("");
	if (sig == SIGWINCH)
		ioctl(0, TIOCSTI, "\2\0");
}
