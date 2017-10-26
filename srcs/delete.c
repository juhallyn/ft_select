/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:50:40 by juhallyn          #+#    #+#             */
/*   Updated: 2017/10/26 15:15:47 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void del_middle(t_select **prev, t_select **to_del, t_select **next)
{
	(*prev)->next = *next;
	(*next)->prev = *prev;
	ft_strdel(&(*to_del)->data);
	free((*to_del)->status);
	free((*to_del));
	(*to_del) = *prev;
}

static void reset_position(t_std **std)
{
	t_select	*tmp;
	int			i;

	i = 0;
	tmp = (*std)->first;
	while (tmp)
	{
		tmp->status->place_index = i;
		tmp = tmp->next;
		i++;
	}
}

void		delete_element(t_std **std, t_select **select)
{
	t_select	*prev;
	t_select	*next;

	prev = NULL;
	next = NULL;
	if ((*select)->prev)
		prev = (*select)->prev;
	if ((*select)->next)
		next = (*select)->next;
	if (prev && next)
	{
		del_middle(&prev, select, &next);
		right_direction(select, (*std)->first, false);
	}
	reset_position(std);
}



// t_select	*connect_element(t_select *prev, t_select *next);
// {
//     - prev -   - TO_DEL -  - next -
//
//				TO_DEL = next;
//
//			TO_DEL  <-  SELECT
//
//		SELECT-> prev = prev;
//
//
//

// }
