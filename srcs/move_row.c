/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_row.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 17:38:13 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/02 18:06:08 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	left_direction(t_select **select)
{
	if (!*select)
		return ;
	if ((*select)->prev)
	{
		move_left(select);
		(*select) = (*select)->prev;
	}
	else
		to_last_element(select);
}

void	right_direction(t_select **select, t_select *first, bool underline)
{
	if (!*select)
		return ;
	if ((*select)->next)
	{
		move_right(select, underline);
		(*select) = (*select)->next;
	}
	else
		reset(select, first, underline);
}

void	move_right(t_select **select, bool underline)
{
	(*select)->status->select = false;
	if (underline == true)
		(*select)->status->underlined = !((*select)->status->underlined);
	print_element(*select);
	if ((*select)->next)
	{
		(*select)->next->status->select = true;
		print_element((*select)->next);
	}
}

void	move_left(t_select **select)
{
	(*select)->status->select = false;
	print_element(*select);
	if ((*select)->prev)
	{
		(*select)->prev->status->select = true;
		print_element((*select)->prev);
	}
}

void	to_last_element(t_select **select)
{
	t_select	*last;

	last = get_last_element(*select);
	(*select)->status->select = false;
	print_element(*select);
	(*select) = last;
	(*select)->status->select = true;
	print_element(*select);
}
