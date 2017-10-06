/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 12:16:10 by juhallyn          #+#    #+#             */
/*   Updated: 2017/10/06 19:42:20 by juhallyn         ###   ########.fr       */
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
	ft_putnbr(sig);
	ft_putchar('\n');
	if (sig == SIGINT)
	{
		ft_putendl("SIGINT Recev");
		exit (0);
	}
}

int		my_put(int c)
{
	write(1, &c, 1);
	return (0);
}

void	underline(void)
{
	unsigned long	buff;
//	ft_putnbr(tgetnum("co"));
//	ft_putchar('\n');
//	ft_putnbr(tgetnum("li"));

	 read(0, &buff, sizeof(int));
	// ft_putstr_fd(tgoto(tgetstr("cm", NULL), 5, 2), 0);
	// ft_putnbr(buff);
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
		ft_putendl_fd("tcgetattr fail", 2);
	change_term(&term);
	// tputs(tgoto(tgetstr("cv", NULL), 0, 0), 1, my_put);
	return (0);
}

void			change_term(struct termios *term)
{
	struct termios	*save;

	save = (struct termios*)malloc(sizeof(term));
	if (!save)
		ft_putendl_fd("save was not alloc", 2);
	term->c_lflag &= (ICANON);
	term->c_lflag |= ISIG;
	term->c_lflag |= (ECHO);
	ft_putnbr(term->c_lflag);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, term);
	while (42)
	 {
		 underline();
	 }
}

int		main(int argc, char **argv)//, char **env)
{
	(void)argc;
	(void)argv;
	signal(SIGINT, signal_handler);
	init_termios();
	return (0);
}
