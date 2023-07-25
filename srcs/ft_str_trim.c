/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_trim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrasa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:28:47 by mkrasa            #+#    #+#             */
/*   Updated: 2023/07/22 14:28:49 by mkrasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	is_whitespace(char ch);
int	count_size_whitespace(char *str);

char	*ft_str_trim_left(char *str)
{
	char	*result;
	int		i;
	int		len;

	i = 0;
	len = ft_str_len(str);
	result = malloc((sizeof(char) * len) + 1);
	if (result == NULL)
		return (NULL);
	while (is_whitespace(str[i]) == 1 && str[i] != '\0')
		i++;
	len = 0;
	while (str[i] != '\0')
	{
		result[len] = str[i];
		i++;
		len++;
	}
	result[len] = '\0';
	return (result);
}

char	*ft_str_trim_right(char *str)
{
	char	*result;
	int		i;
	int		len;
	int		j;

	i = ft_str_len(str) - 1;
	while (i >= 0 && is_whitespace(str[i]))
		i--;
	len = i + 1;
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	j = 0;
	while (j < len)
	{
		result[j] = str[j];
		j++;
	}
	result[len] = '\0';
	return (result);
}

char	*ft_str_trim(char *str)
{
	char	*trimmed_left;
	char	*trimmed;

	trimmed_left = ft_str_trim_left(str);
	if (trimmed_left == NULL)
		return (NULL);
	trimmed = ft_str_trim_right(trimmed_left);
	if (!trimmed)
		return (NULL);
	free (trimmed_left);
	return (trimmed);
}

int	is_whitespace(char ch)
{
	if ((ch == ' ' || (ch >= 9 && ch <= 13)))
		return (1);
	return (0);
}

int	count_size_whitespace(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (is_whitespace(str[i]) == 0)
			len++;
		i++;
	}
	return (len);
}
