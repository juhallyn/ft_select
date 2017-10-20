/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 17:59:29 by juhallyn          #+#    #+#             */
/*   Updated: 2017/10/20 14:14:58 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_select(t_std **std, t_select **select, t_select *first)
{
	unsigned long	key;
	int				argc;
	char			**argv;

	argc = (*std)->argc;
	argv = (*std)->argv;
	key = 0;
	read(0, &key, sizeof(unsigned long));
	if (key == SIZE_CHANGED)
	{
		// init_std(std, argc, argv);
		*std = determinate_position(*std);
		ft_putstr_fd(tgetstr("cl", NULL), 0);
		if (*std)
			print_select(*std, *select);
	}
	if (key == ESC)
		ft_exit("ESC is pressed");
	if (key == RIGHT_ARROW)
		right_direction(select, first, false);
	if (key == SPACE)
		right_direction(select, first, true);
}

void		print_element(t_select *select)
{
	char	*cursor;

	cursor = tgetstr("cm", NULL);
	ft_putstr_fd(tgoto(cursor , select->status->x, select->status->y), 0);
	if (select->status->underlined == true)
		ft_putstr_fd("\x1B[7m", 0);
	if (select->status->select == true)
		ft_putstr_fd("\x1B[4m", 0);
	ft_putstr(select->data);
	ft_putstr_fd("\x1B[0m", 0);
}

void		print_select(t_std *std, t_select *select)
{
	// ft_putstr_fd(tgetstr("cl", NULL));
	while (select && select->status->place_index < (std->index_page + 1) \
	* std->nb_page)
	{
		print_element(select);
		select = select->next;
	}
}
