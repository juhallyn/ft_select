/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:53:30 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/09 16:01:36 by juhallyn         ###   ########.fr       */
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

int					init_term_canon(bool canon)
{
	char			*term_type;
	int				succes;

	if (!(term_type = getenv("TERM")))
	{
		ft_putendl_fd("Could not access to $TERM var", 2);
		exit(-1);
	}
	succes = tgetent(NULL, term_type);
	if (termios_error(succes) == -1)
		exit(-1);
	succes = tcgetattr(0, &term);
	if (succes == -1)
		exit(-1);
	if (!canon)
		to_no_canonial(&term);
	else
		reset_term(&term);
	return (0);
}

void				to_no_canonial(struct termios *term)
{
	term->c_lflag &= ~(ICANON | ECHO);
	term->c_lflag |= ISIG;
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, term);
	ft_putstr_fd(tgetstr("ti", NULL), 0);
	ft_putstr_fd(tgetstr("vi", NULL), 0);
}

int					termios_error(int succes)
{
	if (succes < 0)
		ft_putendl_fd("Could not access the termcap data base.", 2);
	if (succes == 0)
		ft_putendl_fd("Terminal type is not defined", 2);
	if (succes == 0 || succes < 0)
		return (-1);
	return (0);
}
