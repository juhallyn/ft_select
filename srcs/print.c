/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 15:05:58 by juhallyn          #+#    #+#             */
/*   Updated: 2017/10/16 15:44:12 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		init_std(t_std **std, t_select *select)
{
	*std = NULL;
	*std = (t_std*)malloc(sizeof(t_std));
	if (!*std)
		ft_exit("can't allocate std in determinate_position");
	(*std)->max_len = get_max_len(select);
    if (ioctl(0, TIOCGWINSZ, (&(*std)->win)) == -1)
        ft_exit("ioctl fail");
}

void			print_determinate_position(t_select *select)
{
	t_std		*std;
	char		*cursor;
	int			co;

	init_std(&std, select);
	co = std->win.ws_col / std->max_len * std->max_len;
	cursor = tgetstr("cm", NULL);
	while (select)
	{
		if (!co)
		{
			ft_putendl_fd("Windows Is Too Small", 2);
			break ;
		}
		select->status->x = select->status->place_index * std->max_len % co;
		select->status->y = select->status->place_index * std->max_len / co;
		ft_putstr_fd(tgoto(cursor, select->status->x, select->status->y), 0);
		ft_putstr(select->data);
		select = select->next;
	}
	free(std);
}
