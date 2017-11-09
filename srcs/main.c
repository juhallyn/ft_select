/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 12:16:10 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/09 15:56:01 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int argc, char **argv)
{
	t_std		*std;

	std = NULL;
	if (argc < 2)
		print_usage_and_exit();
	ft_signal();
	init_std(&std, argc - 1, argv + 1);
	init_term_canon(false);
	determinate_position(&std);
	print_select(std, std->select);
	while (42)
		ft_select(&std);
	return (0);
}
