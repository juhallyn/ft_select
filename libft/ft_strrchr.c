/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 19:50:04 by juhallyn          #+#    #+#             */
/*   Updated: 2017/03/21 14:53:11 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = ft_strlen(str);
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(str));
	while (*s)
		s++;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)s);
		i--;
		s--;
	}
	return (NULL);
}
