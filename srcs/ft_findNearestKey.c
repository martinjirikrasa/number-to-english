/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findNearestKey.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrasa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:55:57 by mkrasa            #+#    #+#             */
/*   Updated: 2023/07/22 15:55:59 by mkrasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

long long	ft_find_nearest_key(long long number, t_dict dict)
{
	long long	nearkey;
	long long	i;

	i = 0;
	nearkey = 0;
	while (dict[i].key <= number && dict[i].key != -1)
	{
		nearkey = dict[i].key;
		i++;
	}
	return (nearkey);
}
