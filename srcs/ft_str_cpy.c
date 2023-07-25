/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppfiel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:48:51 by ppfiel            #+#    #+#             */
/*   Updated: 2023/07/23 11:48:52 by ppfiel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_str_cpy(char *dest, char *src, long long offset, int amount)
{
	int	i;

	i = 0;
	while (src[offset + i] && i < amount)
	{
		dest[i] = src[offset + i];
		i++;
	}
	dest[i] = '\0';
	return ;
}

void	ft_str_cat(char *dest, char *src, long long offset, int amount)
{
	int	i;

	i = 0;
	while (src[i] && i < amount)
	{
		dest[offset + i] = src[i];
		i++;
	}
	dest[offset + i] = '\0';
	return ;
}
