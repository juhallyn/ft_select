/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 14:35:52 by juhallyn          #+#    #+#             */
/*   Updated: 2017/10/11 18:39:57 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "../libft/libft.h"
# include <termios.h>
# include <term.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <sys/ioctl.h>

/*
**	--	KEY --
*/
// ft_exit("ESC");
// if (key == LEFT_ARROW)
// 	ft_putstr_fd(tgoto(cursor, x--, y), 0);
// if (key == RIGHT_ARROW)
// 	ft_putstr_fd(tgoto(cursor, x++, y), 0);
// if (key == DOWN_ARROW)
// 	ft_putstr_fd(tgoto(cursor, x, y++), 0);
// if (key == UP_ARROW)
// 	ft_putstr_fd(tgoto(cursor, x, y--), 0);
// ft_putstr_fd(tgoto("cursor", 0, 0), 0);
// printf("height %d\nwidth %d\n", height, width);

// while ((*list))
// {
// 	free((*list)->data);
// 	(*list)->data = NULL;
// 	free((*list));
// 	(*list) = (*list)->next;
// }

# define UP_ARROW 		4283163
# define DOWN_ARROW 	4348699
# define LEFT_ARROW 	4479771
# define RIGHT_ARROW	4414235
# define ESC			27
# define SPACE			32

typedef struct			s_status
{
	t_bool				select;
	t_bool				underlined;
}						t_status;

typedef struct			s_select
{
	char				*data;
	struct s_status		*status;
	struct s_select		*next;
}						t_select;


/*
**	--	Functions --
*/

int				init_termios(void);
void			change_term(struct termios *term);

/*
**	--	list.c --
*/

t_select		*add_end(t_select *list, char *data, t_status *stat);
void			init_list(int argc, char **argv, t_select **list);
void			print_list(t_select *list);
void			free_list(t_select **list);

/*
**	--	tools.c --
*/

void			ft_exit(char *message);

/*
**	--	print.c --
*/

int				my_put(int c);
void			print_term(char **argv, int argc);

#endif
