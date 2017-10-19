/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 12:16:10 by juhallyn          #+#    #+#             */
/*   Updated: 2017/10/19 12:14:03 by juhallyn         ###   ########.fr       */
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

int					init_termios(void) // int to
{
	struct termios	term;
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
	t_std		*std;
	t_select	*first;

	std = NULL;
	first = NULL;
	if (argc < 2)
		ft_exit("nb arg");
	init_std(&std, argc - 1, argv + 1);
	init_termios();
	std = determinate_position(std);
	print_select(std, std->select);
	first = std->select;
	while (1)
	{
		ft_select(&std, &(std->select), first);
	}
	// free_std_select(&std);
	// while (1) {}
	return (0);
}
