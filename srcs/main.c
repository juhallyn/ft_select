/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 12:16:10 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/28 13:51:34 by juhallyn         ###   ########.fr       */
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

void	underline(void)
{
	unsigned long	buff;

	read(0, &buff, sizeof(int));
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), 5, 2), 0);
	ft_putnbr(buff);
	// ft_putstr_fd(tgetstr("us", NULL), 0);
	// if (buff[0] == 27 && buff[2] == 27 && buff[3] == 66)
	// 	exit(1);
	// ft_putchar('\n');
	// ft_putnbr(buff[0]);
	// ft_putchar('\n');
	// ft_putnbr(buff[1]);
	// ft_putchar('\n');
	// ft_putnbr(buff[2]);
	// ft_putchar('\n');
	// ft_putnbr(buff[3]);
}

int		init_termios(void)
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
		ft_putendl("tcgetattr fail");
	change_term(&term);
	// tputs(tgoto(tgetstr("cv", NULL), 0, 0), 1, my_put);
	return (0);
}

int		change_term(struct termios *term)
{
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= (ECHO);
	term->c_cc[VMIN] = 1;
	tcsetattr(0, TCSANOW, term);
	while (42)
	{
		underline();
	}
	return (0);
}

int		main(int argc, char **argv)//, char **env)
{
	(void)argc;
	(void)argv;
	init_termios();
	return (0);
}
