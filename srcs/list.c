/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 13:59:45 by juhallyn          #+#    #+#             */
/*   Updated: 2017/10/11 18:45:36 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_select	*add_end(t_select *list, char *data, t_status *stat)
{
	t_select	*new;
	t_select	*tmp;

	tmp = list;
	new = (t_select*)malloc(sizeof(t_select));
	if (!new)
		ft_exit("can't allocate new in add_end");
	new->data = ft_strdup(data);
	new->status = stat;
	new->next = NULL;
	if (list == NULL)
		return (new);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (list);
}

void		init_list(int argc, char **argv, t_select **list)
{
	t_status 	*stat;
	int			i;

	stat = (t_status*)malloc(sizeof(t_status));
	if (!stat)
		ft_exit("can't allocate stat in init_list");
	ft_memset(stat, 0, sizeof(t_status));
	i = 0;
	while (i < argc)
	{
		*list = add_end(*list, argv[i], stat);
		i++;
	}
}

void		print_list(t_select *list)
{
	while (list)
	{
		ft_putendl(list->data);
		list = list->next;
	}
}

void		free_list(t_select **list)
{
	t_select	*tmp;

	while (*list)
	{
		tmp = *list;
		(*list) = (*list)->next;
		free(tmp->data);
		free(tmp->status);
		free(tmp);
	}
	*list = NULL;
}
