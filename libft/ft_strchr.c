/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 14:03:50 by juhallyn          #+#    #+#             */
/*   Updated: 2017/06/10 14:03:53 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strchr(const char *s, int tf)
{
	char	*sptr;
	int		i;
	char	c;

	i = 0;
	if (!s)
		return (NULL);
	sptr = (char *)s;
	c = (char)tf;
	if (*sptr == c)
		return (sptr);
	while (sptr[i++])
	{
		if (sptr[i] == c)
			return (&sptr[i]);
	}
	return ((char *)NULL);
}
