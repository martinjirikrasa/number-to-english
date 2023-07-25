/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrasa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:04:35 by mkrasa            #+#    #+#             */
/*   Updated: 2023/07/23 17:04:37 by mkrasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	free_all_dicts(t_dict base_dict, t_dict extra_dict)
{
	free_dict(base_dict);
	free_dict(extra_dict);
	return ;
}

void	free_dict(t_dict dict)
{
	long long	i;

	i = 0;
	while (dict[i].key != -1)
	{
		free(dict[i].value);
		i++;
	}
	free(dict);
}

void	free_entries(t_dict dict, long long amount)
{
	long long	i;

	i = 0;
	while (i < amount)
	{
		free(dict[i].value);
		i++;
	}
	free(dict);
}

void	free_parts(char **parts)
{
	free(parts[0]);
	free(parts[1]);
	free(parts);
}

void	*free_and_null(t_dict dict, long long amt, char *l, char *v)
{
	if (l != NULL)
		free(l);
	if (v != NULL)
		free(v);
	free_entries(dict, amt);
	return (NULL);
}
