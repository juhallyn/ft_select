/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 15:56:45 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/03 00:30:14 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_signal(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGWINCH, signal_handler);
	signal(SIGCONT, signal_handler);
	signal(SIGTSTP, signal_handler);
}

void		signal_handler(int sig)
{
	if (sig == SIGINT)
		ft_exit("");
	if (sig == SIGWINCH)
		ioctl(0, TIOCSTI, "\2\0");
	if (sig == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		init_term_canon(true);
		ft_putstr_fd(tgetstr("cl", NULL), 0);
		ioctl(0, TIOCSTI, "\032");
	}
	if (sig == SIGCONT)
	{
		ft_signal();
		ft_putstr_fd(tgetstr("cl", NULL), 0);
		init_term_canon(false);
		ioctl(0, TIOCSTI, "\2\0");
	}
}
