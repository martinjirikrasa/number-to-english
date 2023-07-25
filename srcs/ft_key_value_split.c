/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_value_split.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrasa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 10:36:59 by mkrasa            #+#    #+#             */
/*   Updated: 2023/07/23 10:37:00 by mkrasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

int	read_till_col(char *str, char **result);

char	**ft_key_value_split(char *str)
{
	char	**result;
	int		length;
	int		i;

	i = 0;
	result = (char **)malloc(sizeof(char *) * 2);
	if (result == NULL)
		return (NULL);
	result[0] = NULL;
	i = read_till_col(str, result);
	if (i == -1)
		return (NULL);
	i++;
	length = ft_str_len_offset(str, i);
	result[1] = malloc(length + 1);
	ft_str_cpy(result[1], str, i, length);
	return (result);
}

int	read_till_col(char *str, char **result)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ':')
		{
			result[0] = malloc(i + 1);
			if (!result[0])
			{
				free(result);
				return (-1);
			}
			ft_str_cpy(result[0], str, 0, i);
			break ;
		}
		i++;
	}
	return (i);
}
