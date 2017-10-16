/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:39:57 by juhallyn          #+#    #+#             */
/*   Updated: 2017/01/24 17:49:06 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *u_s1;
	unsigned char *u_s2;

	u_s1 = (unsigned char*)s1;
	u_s2 = (unsigned char*)s2;
	while (n > 0 && *u_s1 == *u_s2)
	{
		u_s1++;
		u_s2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*u_s1 - *u_s2);
}
