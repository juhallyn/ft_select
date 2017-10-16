/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 12:16:10 by juhallyn          #+#    #+#             */
/*   Updated: 2017/10/16 15:48:03 by juhallyn         ###   ########.fr       */
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

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		ft_putendl("SIGINT Recev");
		exit (0);
	}
	if (sig == SIGWINCH)
	{
		ft_putendl_fd("WIN SIZE CHANGED", 0);
	}
}

void	ft_select(void)
{
	unsigned long	key;
	char			*cursor;

	key = 0;
	cursor = tgetstr("cm", NULL);
	read(0, &key, sizeof(unsigned long));
	if (key == ESC)
	{
		;
	}
	if (key == UP_ARROW)
	{
		// ft_putstr_fd(tgoto(cursor, win.ws_col, win.ws_row), 0);
	}
}

int					init_termios(void)
{
	struct termios	term;
	char			*term_type;
	int				succes;
	char			*line;

	line = NULL;
	if (!(term_type = getenv("TERM")))
		return (-1);
	succes = tgetent(NULL, term_type);
	if (ft_error(succes) == -1)
		return (-1);
	succes = tcgetattr(0, &term);
	if (succes == -1)
		ft_putendl_fd("tcgetattr fail, Could not access termcap database", 2);
	change_term(&term);
	return (0);
}

void			change_term(struct termios *term)
{
	term->c_lflag &= ~(ICANON | ECHO);
	term->c_lflag |= ISIG;
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, term);
	ft_putstr_fd(tgetstr("ti", NULL), 0);
	// ft_putstr_fd(tgetstr("vi", NULL), 0);
}

int		main(int argc, char **argv)
{
	t_select	*select;

	select = NULL;
	if (argc < 2)
		ft_exit("nb arg");
	signal(SIGINT, signal_handler);
	signal(SIGWINCH, signal_handler);
	init_list(argc - 1, argv + 1, &select);
	init_termios();
	print_determinate_position(select);
	free_list(&select);
	while (1) {}
	return (0);
}
