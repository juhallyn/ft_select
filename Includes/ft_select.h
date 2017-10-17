/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 14:35:52 by juhallyn          #+#    #+#             */
/*   Updated: 2017/10/17 17:36:05 by juhallyn         ###   ########.fr       */
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
// # include "../logger/incs/logger.h"
// # include "../logger/incs/logger_utils.h"

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

// void		print_list(t_select *list)
// {
// 	while (list)
// 	{
// 		ft_putendl(list->data);
// 		list = list->next;
// 	}
// }

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
	int					place_index;
	int					x;
	int					y;
	t_bool				select;
	t_bool				underlined;
}						t_status;

typedef struct			s_select
{
	char				*data;
	struct s_select		*prev;
	struct s_status		*status;
	struct s_select		*next;
}						t_select;

typedef struct			s_std
{
	struct s_select		*select;
	struct winsize		win;
	int					nb_col;
	int					index_page;
	int					nb_page;
	int					max_len;
}						t_std;

/*
**	--	Functions --
*/

int						init_termios(void);
void					change_term(struct termios *term);

/*
**	--	signal.c --
*/

void					ft_signal(void);
void					signal_handler(int sig);

/*
**	--	list.c --
*/

void					add_end(t_select **select, char *data, int place_index);
t_select				*init_data(char *data, int place_index);
void					init_list(int argc, char **argv, t_select **list);
void					print_list(t_select *list);
void					free_list(t_select **list);
void					free_std_select(t_std **std);

/*
**	--	print.c --
*/

void					print_element(t_select *select);
void					print_select(t_std *std, t_select *select);


/*
**	--	struct_init.c --
*/

int						get_max_len(t_select *list);

/*
**	--	positions.c --
*/

void					init_std(t_std **std, int argc, char **argv);
void					determinate_position(t_std *std);

/*
**	--	tools.c --
*/

void					ft_exit(char *message);

#endif
