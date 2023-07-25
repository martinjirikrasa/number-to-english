/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_base_dict.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppfiel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:03:48 by ppfiel            #+#    #+#             */
/*   Updated: 2023/07/22 17:03:50 by ppfiel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	check_line(long long line_length, char *buffer, long long position)
{
	char	*line;
	int		is_valid;

	if (line_length < 1)
		return (line_length);
	line = malloc(line_length + 1);
	if (!line)
		return (-1);
	ft_str_cpy(line, buffer, position, line_length);
	is_valid = ft_is_valid_dict_entry(line);
	free(line);
	return (is_valid);
}

long long	get_entry_amount(char *buffer)
{
	long long	amount;
	long long	position;
	long long	line_length;
	int			is_valid_line;

	position = 0;
	amount = 0;
	while (buffer[position])
	{
		line_length = get_line_length(buffer, position);
		is_valid_line = check_line(line_length, buffer, position);
		if (is_valid_line == 0)
		{
			position++;
			continue ;
		}
		if (is_valid_line == -1)
			return (-1);
		amount++;
		position += line_length + 1;
	}
	return (amount);
}

int	ft_str_to_entry(char *str, t_dict_entry *entry)
{
	char		**parts;
	int			amount_parts;
	char		*key_str;

	if (ft_is_valid_dict_entry(str) != 1)
		return (-1);
	amount_parts = 0;
	parts = ft_key_value_split(str);
	if (!parts)
		return (-1);
	key_str = ft_str_trim(parts[0]);
	if (!key_str)
	{
		free_parts(parts);
		return (-1);
	}
	entry->key = ft_atoi(key_str);
	entry->value = ft_str_trim(parts[1]);
	free(key_str);
	free(parts[0]);
	free(parts[1]);
	free(parts);
	if (!(entry->value))
		return (-1);
	return (0);
}

int	is_key_contained(t_dict dict, long long size, long long key)
{
	long long	i;

	i = 0;
	while (i < size)
	{
		if (dict[i].key == key)
			return (1);
		i++;
	}
	return (0);
}

t_dict	ft_get_dict_from_file(char *filename)
{
	char		*buffer;
	long long	file_size;
	long long	entry_amount;
	t_dict		dict;

	file_size = get_file_size(filename);
	if (file_size == -1)
		return (NULL);
	buffer = malloc(file_size);
	if (!buffer)
		return (NULL);
	if (!read_file_buffered(filename, buffer))
	{
		free(buffer);
		return (NULL);
	}
	entry_amount = get_entry_amount(buffer);
	if (entry_amount == -1)
	{
		free(buffer);
		return (NULL);
	}
	fill_dict(&dict, buffer, entry_amount);
	free(buffer);
	return (dict);
}
