/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:13:56 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/09 15:59:51 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_exit(char *message)
{
	if (message)
		ft_putendl(message);
	init_term_canon(true);
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	exit(0);
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

void	print_usage_and_exit(void)
{
	ft_putendl_fd("ft_select: Too few arguments.\nusage: ./ft_select \
\"some arguments\"", 2);
	exit(-1);
}

void	free_selected_element(t_select **to_del)
{
	ft_strdel(&(*to_del)->data);
	free((*to_del)->status);
	free((*to_del));
}

void	reset(t_std **std, bool underline)
{
	(*std)->select->status->select = false;
	if (underline == true)
		(*std)->select->status->underlined = \
		!((*std)->select->status->underlined);
	print_element((*std)->select);
	(*std)->select = (*std)->first;
	(*std)->select->status->select = true;
	print_element((*std)->select);
}
