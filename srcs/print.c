/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 17:59:29 by juhallyn          #+#    #+#             */
/*   Updated: 2017/10/20 16:51:35 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_select(t_std **std, t_select *first)
{
	unsigned long	key;

	key = 0;
	read(0, &key, sizeof(unsigned long));
	if (key == SIZE_CHANGED)
	{
		print_select(determinate_position(*std), first);
	}
	if (key == ESC)
		ft_exit("ESC is pressed");
	if (key == RIGHT_ARROW)
		right_direction(&(*std)->select, first, false);
	if (key == SPACE)
		right_direction(&(*std)->select, first, true);
}

// void		ft_resize(t_std **std)
// {
//     if ((ioctl(0, TIOCGWINSZ, (std)->win)) == -1)
//         ft_exit("ioctl fail");
// 	if (!(co = std->win.ws_col / std->max_len * std->max_len))
// 	{
// 		ft_putendl_fd("Windows Is Too Small", 2);
// 		return ;
// 	}
// }

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
	ft_putstr_fd(tgetstr("cl", NULL) ,0);
	while (select && select->status->place_index < (std->index_page + 1) \
	* std->nb_page)
	{
		print_element(select);
		select = select->next;
	}
}
