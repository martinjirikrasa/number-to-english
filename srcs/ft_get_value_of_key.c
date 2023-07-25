/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_value_of_key.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrul <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:24:43 by yrul              #+#    #+#             */
/*   Updated: 2023/07/22 18:12:12 by yrul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_get_value_of_key(long long key, t_dict dict)
{
	int	i;

	i = 0;
	while (dict[i].key != -1)
	{
		if (dict[i].key == key)
			return (dict[i].value);
		i++;
	}
	return (0);
}
