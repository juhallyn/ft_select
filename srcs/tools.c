/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:13:56 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/02 18:19:03 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_exit(char *message)
{
	if (message)
		ft_putendl(message);
	init_term_canon(true);
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	exit (0);
}

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


void	free_selected_element(t_select **to_del)
{
	ft_strdel(&(*to_del)->data);
	free((*to_del)->status);
	free((*to_del));
}

void	print_page_index(int i, int total)
{
	ft_putstr("pages (");
	ft_putnbr(i);
	ft_putchar('/');
	ft_putnbr(total);
	ft_putstr(")");
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
