/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 17:59:29 by juhallyn          #+#    #+#             */
/*   Updated: 2017/10/18 19:07:30 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_select(t_std **std, t_select **select, t_select *first)
{
	unsigned long	key;
	char			*cursor;
	t_select		*tmp;

	tmp = *select;
	key = 0;
	cursor = tgetstr("cm", NULL);
	read(0, &key, sizeof(unsigned long));
	if (key == ESC)
	{
		;
	}
	if (key == RIGHT_ARROW)
		right_direction(select, first);
	if (key == SPACE)
		right_direction_space(select, first);

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
	while (select && select->status->place_index < (std->index_page + 1) \
	* std->nb_page)
	{
		print_element(select);
		select = select->next;
	}
}
