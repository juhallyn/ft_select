/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:15:16 by juhallyn          #+#    #+#             */
/*   Updated: 2016/11/16 13:40:53 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t i;
	size_t j;
	size_t len_s1;
	size_t len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	i = 0;
	j = 0;
	while (i < (len_s1 + len_s2))
	{
		i = ft_strlen(s1);
		while (s2[j])
		{
			s1[i] = s2[j];
			i++;
			j++;
		}
	}
	s1[i] = s2[j];
	return (s1);
}
