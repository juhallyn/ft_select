/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:05:45 by juhallyn          #+#    #+#             */
/*   Updated: 2016/11/08 18:50:48 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				i;
	unsigned char		*str;

	i = 0;
	str = (unsigned char*)b;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
