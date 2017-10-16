/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhallyn <juhallyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 16:27:10 by juhallyn          #+#    #+#             */
/*   Updated: 2017/01/08 17:53:20 by juhallyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_atoi(const char *str)
{
	int l;
	int result;
	int n_flag;

	n_flag = 0;
	l = 0;
	result = 0;
	if (ft_strcmp("-2147483648", str) == 0)
		return (-2147483648);
	while (str[l] == ' ' || (str[l] >= '\t' && str[l] <= '\r'))
		l++;
	if (str[l] == '-' || str[l] == '+')
	{
		n_flag = l;
		l++;
	}
	while (str[l] >= '0' && str[l] <= '9')
	{
		result = result * 10 + (str[l] - 48);
		l++;
	}
	if (str[n_flag] == '-')
		result = -result;
	return (result);
}
