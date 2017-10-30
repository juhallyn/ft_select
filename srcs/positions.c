/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 15:05:58 by juhallyn          #+#    #+#             */
/*   Updated: 2017/10/30 17:49:01 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			init_std(t_std **std, int argc, char **argv)
{
	*std = NULL;
	*std = (t_std*)ft_memalloc(sizeof(t_std));
	if (!*std)
		ft_exit("can't allocate std in determinate_position");
	init_list(argc, argv, &((*std)->select));
	(*std)->first = (*std)->select;
	(*std)->argc = argc;
	(*std)->max_len = get_max_len((*std)->select);
}

bool			determinate_position(t_std **std)
{
	t_select	*tmp;
	int			co;

	if ((ioctl(0, TIOCGWINSZ, &(*std)->win)) == -1)
		ft_exit("ioctl fail");
	if (!(co = (*std)->win.ws_col / (*std)->max_len * (*std)->max_len))
	{
		ft_putstr_fd(tgetstr("cl", NULL), 0);
		ft_putendl_fd("Windows Is Too Small", 2);
		return (false);
	}
	(*std)->nb_col = co / (*std)->max_len;
	(*std)->max_elem_page = (*std)->nb_col * ((*std)->win.ws_row - 0);
	(*std)->nb_page = determinate_nb_page((*std)->argc, (*std)->max_elem_page);
	tmp = (*std)->first;
	while (tmp)
	{
		tmp->status->x = tmp->status->place_index * (*std)->max_len % co;
		tmp->status->y = tmp->status->place_index * (*std)->max_len / co;
		tmp = tmp->next;
	}
	return (true);
}

int				determinate_nb_page(int argc, int max_elem_page)
{
	int		nb_page;

	nb_page = 0;
	while ((argc - max_elem_page) > 0)
	{
		argc = (argc - max_elem_page);
		nb_page++;
	}
	return (nb_page);
}
