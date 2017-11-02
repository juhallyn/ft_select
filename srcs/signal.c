/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 15:56:45 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/02 22:21:05 by juhallyn         ###   ########.fr       */
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
		// printf("SIGTSTP RECEVE\n");
		printf("\n\nSIGSTP RECEVE\n");
		char	st[2];
		//
		st[0] = term.c_cc[VSUSP];
		st[1] = '\0';
		signal(SIGTSTP, SIG_DFL);
		// ft_putstr_fd(tgetstr("cl", NULL), 0);
		init_term_canon(true);
		// tcsetattr(0, 0, &(term));
		ioctl(0, TIOCSTI, "\032");
		// st[0] = term.c_cc[VSUSP];
		//
		// suspend_term();
		// // signal(SIGTSTP, 0);
	}
	if (sig == SIGCONT)
	{
		// if (getpgid(0) != tcgetpgrp(0))
		// 	ioctl(0, TIOCSTI, "\032");
		ft_signal();
		ft_putstr_fd(tgetstr("cl", NULL), 0);
		init_term_canon(false);
		ioctl(0, TIOCSTI, "\2\0");
	}
}
