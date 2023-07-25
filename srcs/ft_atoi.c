/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrul <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:11:25 by yrul              #+#    #+#             */
/*   Updated: 2023/07/22 15:51:14 by yrul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

long long	ft_atoi_mistake(char *str, long long i);

long long	ft_atoi(char *str)
{
	long long	res; 
	long long	i;

	res = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	res = ft_atoi_mistake(str, i);
	if (res == -1)
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res);
}

long long	ft_atoi_mistake(char *str, long long j)
{
	long long	res;

	res = 0;
	while (str[j])
	{
		if (!(str[j] >= '0' && str[j] <= '9'))
			res = -1;
		j++;
	}
	return (res);
}
