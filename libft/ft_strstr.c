/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:51:07 by juhallyn          #+#    #+#             */
/*   Updated: 2017/01/24 18:17:04 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char *t_big;
	const char *t_little;

	if (*little == '\0')
		return ((char*)big);
	while (*big)
	{
		t_big = big;
		t_little = little;
		while (*t_little != '\0' && *t_big == *t_little)
		{
			t_big++;
			t_little++;
		}
		if (*t_little == '\0')
			return ((char*)big);
		big++;
	}
	return (NULL);
}
