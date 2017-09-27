/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 12:16:10 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/27 19:58:03 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"


int		ft_error(int succes)
{
	if (succes < 0)
		ft_putendl_fd("Could not access the termcap data base.", 2);
	if (succes == 0)
		ft_putendl_fd("Terminal type is not defined", 2);
	if (succes == 0 || succes < 0)
		return (-1);
	return (0);
}

int		my_put(int c)
{
	write(1, &c, 1);
	return (0);
}

int		whats_key(void)
{
	char	buff[3];

	read(0, buff, 3);
	if (buff[0] == 27)
		ft_putendl("fleche");
	else
		ft_putendl("other");
	return (0);
}

int		init_termios(void)
{
	struct termios	term;
	char			*term_type;
	int				succes;
	char			*line;
	int				*ptr;

	line = NULL;
	if (!(term_type = getenv("TERM")))
		return (-1);
	succes = tgetent(NULL, term_type);
	if (ft_error(succes) == -1)
		return (-1);
	succes = tcgetattr(0, &term);
	if (succes == -1)
		ft_putendl("tcgetattr fail");
	change_term(&term);
	// whats_key();
	// ft_putstr_fd(tgetstr("cv", NULL), 0);
	// tputs(tgoto(tgetstr("cv", NULL), 0, 0), 1, my_put);
	return (0);
}

int		change_term(struct termios *term)
{
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	tcsetattr(0, TCSANOW, term);
	return (0);
}

int		main(int argc, char **argv)//, char **env)
{
	(void)argc;
	(void)argv;
	init_termios();
	return (0);
}
