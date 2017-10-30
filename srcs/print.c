/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 17:59:29 by juhallyn          #+#    #+#             */
/*   Updated: 2017/10/30 16:17:46 by juhallyn         ###   ########.fr       */
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
		log_error("/!\\ RESIZE /!\\");
		if (determinate_position(*std))
		{
			*std = determinate_position(*std);
			print_select(*std, first);
		}
	}
	if (key == DEL)
	{
		delete_element(std, &(*std)->select);
		if (determinate_position(*std))
		{
			*std = determinate_position(*std);
			print_select(*std, (*std)->first);
		}
	}
	if (key == DOWN_ARROW)
	{
		printf("\n\n\n\n\n argc == %d \n\n", (*std)->argc);
		printf("\n\n\n max_elem_page == %d \n", (*std)->max_elem_page);
		printf("\n\n\n nb_page == %d \n", (*std)->nb_page);
		// printf("\n\n\n index_page * max_elem_page == %d \n", (*std)->index_page +1 * (*std)->max_elem_page);
		// if ((*std)->argc > (*std)->max_elem_page)
		// {
		// }
	}
	if (key == ENTER)
		print_selected_arg((*std)->first);
	if (key == ESC)
		ft_exit("ESC is pressed");
	if (key == LEFT_ARROW)
		left_direction(&(*std)->select);
	if (key == RIGHT_ARROW)
		right_direction(&(*std)->select, first, false);
	if (key == SPACE)
		right_direction(&(*std)->select, first, true);
}

void		print_selected_arg(t_select *select)
{
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	while (select)
	{
		if (select->status->underlined)
		{
			ft_putstr_fd(select->data, 1);
			ft_putchar_fd(' ', 1);
		}
		select = select->next;
	}
	ft_putchar('\n');
	init_term_canon(true);
	exit (0);
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
	ft_putstr_fd(select->data, 0);
	ft_putstr_fd("\x1B[0m", 0);
}

void		print_select(t_std *std, t_select *select)
{
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	while (select && select->status->place_index < (std->index_page + 1) \
	* std->max_elem_page)
	{
		print_element(select);
		select = select->next;
	}
}
