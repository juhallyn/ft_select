/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 13:59:45 by juhallyn          #+#    #+#             */
/*   Updated: 2017/10/24 15:24:18 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_select	*init_data(char *data, int place_index)
{
	t_select	*element;

	element = (t_select*)malloc(sizeof(t_select));
	if (!element)
		ft_exit("can't allocate element in init_data");
	element->status = malloc(sizeof(t_status));
	if (!element->status)
		ft_exit("can't allocate element->status in init_data");
	element->data = ft_strdup(data);
	element->status->place_index = place_index;
	element->prev = NULL;
	element->next = NULL;
	return (element);
}

void		add_end(t_select **select, char *data, int place_index)
{
	t_select	*tmp;

	if (*select == NULL)
		ft_putendl("C'est null");
	if (!*select)
	{
		*select = init_data(data, place_index);
		(*select)->status->select = true;
	}
	else
	{
		tmp = *select;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = init_data(data, place_index);
		tmp->next->prev = tmp;
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

void		init_list(int argc, char **argv, t_select **list)
{
	int			i;

	i = 0;
	while (i < argc)
	{
		add_end(list, argv[i], i);
		i++;
	}
}

t_select	*get_last_element(t_select *select)
{
	while (select->next)
		select = select->next;
	return (select);
}

// void		free_list(t_select **list)
// {
// 	t_select	*tmp;
//
// 	while (*list)
// 	{
// 		tmp = *list;
// 		(*list) = (*list)->next;
// 		free(tmp->data);
// 		free(tmp->status);
// 		free(tmp);
// 	}
// 	*list = NULL;
// }

void		free_std_select(t_std **std)
{
	t_select	*tmp;

	while ((*std)->select)
	{
		tmp = (*std)->select;
		(*std)->select = (*std)->select->next;
		free(tmp->data);
		free(tmp->status);
		free(tmp);
	}
	(*std)->select = NULL;
	free(*std);
}
