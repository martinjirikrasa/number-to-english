/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppfiel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:31:20 by ppfiel            #+#    #+#             */
/*   Updated: 2023/07/23 21:31:22 by ppfiel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	read_file_buffered(char *filename, char *result)
{
	char		buffer[1024];
	long long	read_bytes;
	long long	total_bytes;
	int			file;

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (0);
	read_bytes = 1;
	total_bytes = 0;
	while (read_bytes > 0)
	{
		read_bytes = read(file, buffer, 1024 - 1);
		buffer[read_bytes] = '\0';
		ft_str_cat(result, buffer, total_bytes, read_bytes);
		total_bytes += read_bytes;
	}
	close(file);
	return (read_bytes != -1);
}

long long	get_file_size(char *filename)
{
	int			file;
	long long	size;
	int			read_bytes;
	char		*buffer[1024];

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (-1);
	size = 0;
	read_bytes = read(file, buffer, 1024);
	while (read_bytes > 0)
	{
		size += read_bytes;
		read_bytes = read(file, buffer, 1024);
	}
	close(file);
	return (size);
}

int	get_line_length(char *str, long long offset)
{
	int	i;

	i = 0;
	while (str[offset + i])
	{
		if (str[offset + i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
