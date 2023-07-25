/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrasa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:24:22 by mkrasa            #+#    #+#             */
/*   Updated: 2023/07/22 13:24:24 by mkrasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_str_len(char *str)
{
	int	i;	

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_str_len_offset(char *str, int offset)
{
	int	i;

	i = 0;
	while (str[offset + i])
	{
		i++;
	}
	return (i);
}
