/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 12:16:10 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/03 00:42:24 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int					ft_error(int succes)
{
	if (succes < 0)
		ft_putendl_fd("Could not access the termcap data base.", 2);
	if (succes == 0)
		ft_putendl_fd("Terminal type is not defined", 2);
	if (succes == 0 || succes < 0)
		return (-1);
	return (0);
}

int		main(int argc, char **argv)
{
	logger_init(7, "./log");
	t_std		*std;

	std = NULL;
	if (argc < 2)
		ft_exit("nb arg");
	ft_signal();
	init_std(&std, argc - 1, argv + 1);
	init_term_canon(false);
	determinate_position(&std);
	print_select(std, std->select);
	while (42)
		ft_select(&std);
	return (0);
}
