/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 14:02:41 by juhallyn          #+#    #+#             */
/*   Updated: 2017/06/10 14:03:13 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ret;

	if ((ret = ft_strnew(ft_strlen(str) + 1)) == NULL)
		return ((char *)0);
	ft_strcpy(ret, str);
	return (ret);
}
