/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:13:56 by juhallyn          #+#    #+#             */
/*   Updated: 2017/10/30 16:42:56 by juhallyn         ###   ########.fr       */
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
