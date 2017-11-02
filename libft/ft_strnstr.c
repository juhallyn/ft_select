/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:21:03 by juhallyn          #+#    #+#             */
/*   Updated: 2017/01/24 18:24:14 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t			n;
	unsigned int	i;
	unsigned int	tmp;

	n = ft_strlen(find);
	if (n == 0)
		return (char*)(str);
	i = 0;
	while (str[i] != '\0' && (n + i) <= len)
	{
		tmp = 0;
		while (find[tmp] == str[tmp + i])
		{
			if (tmp == (n - 1))
				return ((char*)str + i);
			tmp++;
		}
		i++;
	}
	return (NULL);
}
