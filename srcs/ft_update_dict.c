/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_ref_dict.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppfiel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:44:46 by ppfiel            #+#    #+#             */
/*   Updated: 2023/07/23 13:44:46 by ppfiel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_update_dict(t_dict base_dict, t_dict ref_dict)
{
	int			i;
	long long	amount_keys;
	char		*value;	

	amount_keys = 0;
	while (base_dict[amount_keys].key != -1)
	{
		amount_keys++;
	}
	i = 0;
	if (ref_dict == NULL)
		return (0);
	while (base_dict[i].key != -1)
	{
		value = ft_get_value_of_key(base_dict[i].key, ref_dict);
		if (value == NULL)
			return (0);
		free(base_dict[i].value);
		base_dict[i].value = value;
		i++;
	}
	return (1);
}
