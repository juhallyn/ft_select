/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 17:59:29 by juhallyn          #+#    #+#             */
/*   Updated: 2017/10/24 19:32:14 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_select(t_std **std, t_select *first)
{
	unsigned long	key;
	t_select		*last;

	key = 0;
	last = get_last_element((*std)->select);
	read(0, &key, sizeof(unsigned long));
	// printf("\n\n\n%ld\n", key);
	if (key == SIZE_CHANGED)
	{
		log_error("/!\\ RESIZE /!\\");
		if (determinate_position(*std))
			print_select(*std, first);
	}
	if (key == DEL)
	{
		delete_element(std, &(*std)->select);
		if (determinate_position(*std))
			print_select(*std, first);
	}
	if (key == ESC)
		ft_exit("ESC is pressed");
	if (key == LEFT_ARROW)
		left_direction(&(*std)->select);
	if (key == RIGHT_ARROW)
		right_direction(&(*std)->select, first, false);
	if (key == SPACE)
		right_direction(&(*std)->select, first, true);
}

void		print_element(t_select *select)
{
	char	*cursor;

	log_info("[%d] Select de x [%d] && Select de y [%d]",select->status->place_index,\
	select->status->x,select->status->y);

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
	ft_putstr_fd(tgetstr("cl", NULL) ,0);
	while (select && select->status->place_index < (std->index_page + 1) \
	* std->nb_page)
	{
		print_element(select);
		select = select->next;
	}
}
