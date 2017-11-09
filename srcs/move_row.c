/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_row.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 17:38:13 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/09 15:58:40 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	left_direction(t_std **std)
{
	if (!(*std)->select)
		return ;
	if ((*std)->select->prev)
	{
		move_left(std);
		(*std)->select = (*std)->select->prev;
	}
	else
		to_last_element(&(*std)->select);
}

void	right_direction(t_std **std, bool underline)
{
	if (!(*std)->select)
		return ;
	if ((*std)->select->next)
	{
		move_right(std, underline);
		(*std)->select = (*std)->select->next;
	}
	else
		reset(std, underline);
}

void	move_right(t_std **std, bool underline)
{
	(*std)->select->status->select = false;
	if (underline == true)
		(*std)->select->status->underlined = \
		!(*std)->select->status->underlined;
	print_element((*std)->select);
	if ((*std)->select->next)
	{
		(*std)->select->next->status->select = true;
		print_element((*std)->select->next);
	}
}

void	move_left(t_std **std)
{
	(*std)->select->status->select = false;
	print_element((*std)->select);
	if ((*std)->select->prev)
	{
		(*std)->select->prev->status->select = true;
		print_element((*std)->select->prev);
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
