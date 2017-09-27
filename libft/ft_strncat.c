/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:12:17 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/15 14:52:39 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;
	size_t x;

	i = 0;
	x = 0;
	j = 0;
	i = ft_strlen(s1);
	if (!s2 || !s1)
		return (s1);
	while (s2[j] && x < n)
	{
		s1[i] = s2[j];
		x++;
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
