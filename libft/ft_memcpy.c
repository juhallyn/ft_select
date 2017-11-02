/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:28:57 by juhallyn          #+#    #+#             */
/*   Updated: 2017/01/24 17:39:01 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*t_dst;
	const char	*t_src;

	t_dst = dst;
	t_src = src;
	while (n-- > 0)
		*t_dst++ = *t_src++;
	return (dst);
}
