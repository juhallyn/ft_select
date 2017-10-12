/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:22:29 by juhallyn          #+#    #+#             */
/*   Updated: 2017/10/12 18:49:28 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		determinate_position(t_select *select)
{
	struct winsize		win;
	char				*cursor;
	int					x;
	int					y;
	int					max_len;

	max_len = get_max_len(select);
	if (ioctl(0, TIOCGWINSZ, &win) == -1)
		ft_exit("ioctl fail");
	// printf("col %d\n", win.ws_col);
	// printf("row %d\n", win.ws_col);
	int co = win.ws_col / max_len * max_len;
	cursor = tgetstr("cm", NULL);
	while (select)
	{
		y = select->status->place_index * max_len / co;
		x = select->status->place_index * max_len % co;
		log_trace("x = %d  y = %d max_len = %d, co = %d", x, y, max_len, co);
		ft_putstr_fd(tgoto(cursor, x, y), 0);
		ft_putstr(select->data);
		// ft_putstr_fd(tgoto(select->data, x, y), 0);
		sleep(1);
		select = select->next;
	}
	return (0);
}
