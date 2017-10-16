/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:31:17 by juhallyn          #+#    #+#             */
/*   Updated: 2017/01/23 17:37:04 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char *t_dst;
	char *t_src;

	t_dst = (char*)dst;
	t_src = (char*)src;
	if (t_src < t_dst)
	{
		t_src = t_src + n - 1;
		t_dst = t_dst + n - 1;
		while (n > 0)
		{
			*t_dst-- = *t_src--;
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			*t_dst++ = *t_src++;
			n--;
		}
	}
	return (dst);
}
