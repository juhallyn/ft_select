/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_col.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:10:31 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/09 15:57:50 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

bool		move_down(t_std **std)
{
	int			i;
	t_select	*tmp;

	i = 0;
	tmp = (*std)->select;
	while (i < (*std)->nb_col && tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	if (i == (*std)->nb_col)
	{
		i = 0;
		while (i < (*std)->nb_col)
		{
			right_direction(std, false);
			i++;
		}
		return (true);
	}
	return (false);
}

bool		move_up(t_std **std)
{
	int			i;
	t_select	*tmp;

	i = 0;
	tmp = (*std)->select;
	while (i < (*std)->nb_col && tmp->prev)
	{
		tmp = tmp->prev;
		i++;
	}
	if (i == (*std)->nb_col)
	{
		i = 0;
		while (i < (*std)->nb_col)
		{
			left_direction(std);
			i++;
		}
		return (true);
	}
	return (false);
}
