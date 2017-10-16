/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 15:03:53 by juhallyn          #+#    #+#             */
/*   Updated: 2017/01/31 16:04:11 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	const char *str;

	if (s == NULL)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (*s == '\0')
		return (ft_strnew(0));
	str = s + (ft_strlen(s) - 1);
	while (*str == ' ' || *str == '\n' || *str == '\t')
		str--;
	return (ft_strsub(s, 0, str - s + 1));
}
