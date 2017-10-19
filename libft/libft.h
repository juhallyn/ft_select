/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:03:27 by juhallyn          #+#    #+#             */
/*   Updated: 2017/10/19 12:13:45 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFF_SIZE 256

typedef enum		e_bool
{
	false = 0,
	true = 1,
}					t_bool;

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, void const *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_atoi(const char *str);
void	ft_putchar(char c);
void	ft_putstr(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isascii(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
int		ft_isprint(int c);
void	ft_putnbr(int nb);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	*ft_memalloc(size_t size);
char	*ft_strrchr(const char *s, int c);
int		ft_isalpha(int c);
char	*ft_strnew(size_t size);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strnew(size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strstr(const char *big, const char *little);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
void	ft_memdel(void **ap);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char*));
char	*ft_strmap(char const *s, char (*f)(char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	**ft_strsplit(char const *s, char c);
char	*ft_strtrim(char const *s);
char	*ft_itoa(int n);
char	*ft_strncpy(char *dst, const char *src, size_t len);
void	ft_arraydel(char ***array);
size_t	ft_arraylen(char **argv);
int		get_next_line(int const fd, char **line);

#endif
