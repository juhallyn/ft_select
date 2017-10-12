/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:32:46 by juhallyn          #+#    #+#             */
/*   Updated: 2017/10/12 18:49:08 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		my_put(int c)
{
	write(1, &c, 1);
	return (0);
}

void	print_term(char **argv, int argc)
{
	int		i;
	int		height;
	int		width;

	i = 0;
	height = tgetnum("li");
	width = tgetnum("co");
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	tgetstr("nd", NULL);
	// ft_putstr_fd(tgetstr("cm", NULL), 0);
	// // tgoto();
	// while (argv[i])
	// {
	// 	tputs(argv[i], 0, my_put);
	// 	ft_putendl("");
	// // 	ft_putnbr(ret);
	// // 	ft_putendl("");
	// 	i++;
	// }
}
