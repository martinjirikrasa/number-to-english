/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_dict_entry.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrasa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:54:25 by mkrasa            #+#    #+#             */
/*   Updated: 2023/07/22 16:54:28 by mkrasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		is_valid_number(char *number);
int		is_valid_value(char *value);

int	ft_is_valid_dict_entry(char *row_string)
{
	char	**split_result;
	int		i;
	int		ret;

	ret = 1;
	if (row_string[0] == '\0')
		return (0);
	split_result = ft_key_value_split(row_string);
	if (split_result == NULL)
		return (-1);
	if (split_result[0] == NULL)
	{
		free(split_result[1]);
		free(split_result);
		return (-1);
	}
	i = 0;
	if (!is_valid_number(split_result[0]) || !is_valid_value(split_result[1]))
		ret = -1;
	free_parts(split_result);
	return (ret);
}

int	is_valid_number(char *number)
{
	int	i;

	i = 0;
	while (number[i] == ' ' || number[i] == '\0')
		return (0);
	while (number[i] >= '0' && number[i] <= '9')
	{
		i++;
	}
	while (number[i])
	{
		if (!(number[i] == ' '))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_value(char *value)
{
	int	i;

	i = 0;
	while (value[i])
	{
		if (value[i] >= 33 && value[i] < 127)
			return (1);
		i++;
	}
	return (0);
}
