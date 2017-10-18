/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 17:38:13 by juhallyn          #+#    #+#             */
/*   Updated: 2017/10/18 19:08:52 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	right_direction_space(t_select **select, t_select *first)
{
	if ((*select)->next)
	{
		underline(select); // pointeur sur fonction (())
		(*select) = (*select)->next;
	}
	else
		reset(select, first);
}

void	underline(t_select **select)
{
	(*select)->status->select = false;
	if ((*select)->status->underlined)
		(*select)->status->underlined = false;
	else
		(*select)->next->status->underlined = true;
	print_element((*select));
}

void	right_direction(t_select **select, t_select *first)
{
	if ((*select)->next)
	{
		move_right(select); // pointeur sur fonction (())
		(*select) = (*select)->next;
	}
	else
		reset(select, first);
}

void	move_right(t_select **select)
{
	(*select)->status->select = false;
	print_element(*select);
	if ((*select)->next)
	{
		(*select)->next->status->select = true;
		print_element((*select)->next);
	}
}

void	reset(t_select **select, t_select *first)
{
	(*select)->status->select = false;
	print_element(*select);
	(*select) = first;
	(*select)->status->select = true;
	print_element(*select);
}
