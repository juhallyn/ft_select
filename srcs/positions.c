/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 15:05:58 by juhallyn          #+#    #+#             */
/*   Updated: 2017/10/19 12:30:30 by juhallyn         ###   ########.fr       */
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
	(*std)->max_len = get_max_len((*std)->select);
    if (ioctl(0, TIOCGWINSZ, (&(*std)->win)) == -1)
        ft_exit("ioctl fail");
}

t_std			*determinate_position(t_std *std)
{
	t_select	*first;
	char		*cursor;
	int			co;

	if (!(co = std->win.ws_col / std->max_len * std->max_len))
	{
		ft_putendl_fd("Windows Is Too Small", 2);
		return (NULL);
	}
	std->nb_col = co / std->max_len;
	std->nb_page = std->nb_col * (std->win.ws_row - 1);
	cursor = tgetstr("cm", NULL);
	first = std->select;
	while (std->select)
	{
		std->select->status->x = std->select->status->place_index * \
		std->max_len % co;
		std->select->status->y = std->select->status->place_index * \
		std->max_len / co;
		std->select = std->select->next;
	}
	std->select = first;
	return (std);
}
