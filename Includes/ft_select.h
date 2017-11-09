/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 14:35:52 by juhallyn          #+#    #+#             */
/*   Updated: 2017/11/09 16:03:26 by juhallyn         ###   ########.fr       */
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
# include <stdbool.h>
# include "../logger/incs/logger.h"
# include "../logger/incs/logger_utils.h"

/*
**	--	KEYS --
*/

# define UP_ARROW 		4283163
# define DOWN_ARROW 	4348699
# define LEFT_ARROW 	4479771
# define RIGHT_ARROW	4414235
# define ESC			27
# define SPACE			32
# define DEL			2117294875
# define ENTER			10

/*
**	--	SIGWINCH --
*/

# define SIZE_CHANGED	2

/*
**	--	struct --
*/

static struct termios	term;

typedef struct			s_status
{
	int					place_index;
	int					x;
	int					y;
	bool				select;
	bool				underlined;
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
	struct s_select		*first;
	struct winsize		win;
	int					nb_col;
	int					nb_page;
	int					max_elem_page;
	int					argc;
	char				**argv;
	int					max_len;
}						t_std;

/*
**					--	Functions --
*/

/*
**	--	term.c --
*/

int						termios_error(int succes);
void					reset_term(struct termios *term);
int						init_term_canon(bool canon);
void					to_no_canonial(struct termios *term);
void					suspend_term(void);

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
t_select				*get_last_element(t_select *select);

/*
**	--	print.c --
*/

void					ft_select(t_std **std);
void					print_selected_arg(t_select *select);
void					refresh(t_std **std, t_select *first);
void					print_element(t_select *select);
void					print_select(t_std *std, t_select *select);

/*
**	--	move_row.c --
*/

void					left_direction(t_std **std);
void					right_direction(t_std **std, bool underline);
void					move_right(t_std **std, bool underline);
void					move_left(t_std **std);
void					to_last_element(t_select **select);

/*
**	-- move_col.c   --
*/

bool					move_down(t_std **std);
bool					move_up(t_std **std);

/*
**	--	delete.c --
*/

void					delete_element(t_std **std, t_select **select);

/*
**	--	positions.c --
*/

void					init_std(t_std **std, int argc, char **argv);
bool					determinate_position(t_std **std);
int						determinate_nb_page(int argc, int max_elem_page);

/*
**	--	tools.c --
*/

void					ft_exit(char *message);
int						get_max_len(t_select *list);
void					print_usage_and_exit(void);
void					free_selected_element(t_select **to_del);
void					reset(t_std **std, bool underline);

#endif
