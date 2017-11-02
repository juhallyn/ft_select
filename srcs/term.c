/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:53:30 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/02 21:16:31 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				reset_term(struct termios *term)
{
	term->c_lflag &= (ICANON);
	term->c_lflag |= ISIG;
	term->c_lflag |= ECHO;
	ft_putstr_fd(tgetstr("ve", NULL), 0);
	tcsetattr(0, TCSANOW, term);
}

void				suspend_term(void)
{
	char	st[2];

	st[0] = term.c_cc[VSUSP];
	st[0] = '\0';
	signal(SIGTSTP, 0);
	tcsetattr(0, 0, &(term));
	// init_term_canon(true);
	// ft_signal();
	ioctl(0, TIOCSTI, st);
}

int					init_term_canon(bool canon)
{
	char			*term_type;
	int				succes;

	if (!(term_type = getenv("TERM")))
		return (-1);
	succes = tgetent(NULL, term_type);
	if (ft_error(succes) == -1)
		return (-1);
	succes = tcgetattr(0, &term);
	if (succes == -1)
		ft_putendl_fd("tcgetattr fail, Could not access termcap database", 2);
	if (!canon)
		to_no_canonial(&term);
	else
		reset_term(&term);
	return (0);
}

void			to_no_canonial(struct termios *term)
{
	term->c_lflag &= ~(ICANON | ECHO);
	term->c_lflag |= ISIG;
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, term);
	ft_putstr_fd(tgetstr("ti", NULL), 0);
	ft_putstr_fd(tgetstr("vi", NULL), 0);
}
