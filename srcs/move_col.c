/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_col.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:10:31 by juhallyn          #+#    #+#             */
/*   Updated: 2017/10/30 18:42:06 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

bool		move_down_if_possible(t_select **select, t_select *first, int nb_col)
{
	int			i;
	t_select	*tmp;

	i = 0;
	tmp = *select;
	while (i < nb_col && tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	if (i == nb_col)
	{
		i = 0;
		while (i < nb_col)
		{
			right_direction(select, first, false);
			i++;
		}
		return (true);
	}
	return (false);
}

bool		move_up_if_possible(t_select **select, int nb_col)
{
	int			i;
	t_select	*tmp;

	i = 0;
	tmp = *select;
	while (i < nb_col && tmp->prev)
	{
		tmp = tmp->prev;
		i++;
	}
	if (i == nb_col)
	{
		i = 0;
		while (i < nb_col)
		{
			left_direction(select);
			i++;
		}
		return (true);
	}
	return (false);
}
