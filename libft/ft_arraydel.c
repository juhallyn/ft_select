/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:10:44 by juhallyn          #+#    #+#             */
/*   Updated: 2017/09/14 17:11:02 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_arraydel(char ***array)
{
	size_t	index;
	size_t	len;
	char	**tmp;

	index = 0;
	len = ft_arraylen(*array);
	tmp = *array;
	while (index < len)
	{
		free(tmp[index]);
		tmp[index] = NULL;
		index++;
	}
	free(tmp);
	tmp = NULL;
}
