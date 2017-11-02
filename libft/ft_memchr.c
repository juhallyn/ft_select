/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:40:00 by juhallyn          #+#    #+#             */
/*   Updated: 2017/03/21 15:08:41 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	i = 0;
	dest = (unsigned char *)s;
	while (i < n)
	{
		if (*dest == (unsigned char)c)
			return ((void *)dest);
		dest++;
		i++;
	}
	return (NULL);
}
