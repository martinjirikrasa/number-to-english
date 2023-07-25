/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_dict_from_buffer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppfiel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:19:03 by ppfiel            #+#    #+#             */
/*   Updated: 2023/07/23 21:19:04 by ppfiel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_dict_entry	*is_val_li(t_dict_entry *e, char *b, long long i, long long le)
{
	char	*line;

	line = malloc(le + 1);
	if (!line)
		return (NULL);
	ft_str_cpy(line, b, i, le);
	if (ft_str_to_entry(line, e) == -1)
	{
		free(line);
		return (NULL);
	}
	free(line);
	return (e);
}

long long	set_ent_inc(t_dict *d, long long *ce, t_dict_entry e, long long le)
{
	(*d)[*ce] = e;
	(*ce)++;
	return (le + 1);
}

int	init_fill(long long *i, long long *ce, long long a, t_dict *dict)
{
	*i = 0;
	*ce = 0;
	*dict = malloc((a + 1) * sizeof(t_dict_entry));
	if (!*dict)
		return (0);
	return (1);
}

void	add_terminating_dict_entry(t_dict dict, long long index)
{
	t_dict_entry	entry;

	entry.key = -1;
	entry.value = NULL;
	dict[index] = entry;
	return ;
}

void	*fill_dict(t_dict *dict, char *buffer, long long amount)
{
	long long		i;
	long long		current_entry;
	long long		line_length;
	t_dict_entry	entry;

	if (!init_fill(&i, &current_entry, amount, dict))
		return (NULL);
	while (buffer[i])
	{
		line_length = get_line_length(buffer, i);
		if (line_length == -1)
			return (free_and_null(*dict, current_entry, NULL, NULL));
		else if (line_length == 0)
		{
			i++;
			continue ;
		}
		if (!is_val_li(&entry, buffer, i, line_length))
			return (free_and_null(*dict, current_entry, NULL, NULL));
		if (is_key_contained(*dict, current_entry, entry.key))
			return (free_and_null(*dict, current_entry, NULL, entry.value));
		i += set_ent_inc(dict, &current_entry, entry, line_length);
	}
	add_terminating_dict_entry(*dict, amount);
	return (NULL);
}
