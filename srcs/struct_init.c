/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:04:41 by juhallyn          #+#    #+#             */
/*   Updated: 2017/10/12 17:21:49 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		get_max_len(t_select *list)
{
	int		max_len;
	int		cmp_len;

	max_len = 0;
	while (list)
	{
		cmp_len = ft_strlen(list->data);
		if (max_len < cmp_len)
			max_len = cmp_len;
		list = list->next;
	}
	return (max_len + 5);
}
