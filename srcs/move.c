/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 17:38:13 by juhallyn          #+#    #+#             */
/*   Updated: 2017/10/19 12:16:04 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	right_direction(t_select **select, t_select *first, bool underline)
{
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

void	reset(t_select **select, t_select *first, bool underline)
{
	(*select)->status->select = false;
	if (underline == true)
		(*select)->status->underlined = !((*select)->status->underlined);
	print_element(*select);
	(*select) = first;
	(*select)->status->select = true;
	print_element(*select);
}
