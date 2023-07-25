/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrasa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:46:02 by mkrasa            #+#    #+#             */
/*   Updated: 2023/07/22 20:46:04 by mkrasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

void	handle_result1(long long base_key, t_dict dict);
void	handle_result_not1(long long result, long long base_key, t_dict dict);
void	p_space(long long res, long long num, long long base_k, t_dict dict);

void	ft_print_number(long long number, t_dict dict)
{
	long long	base_key;
	long long	result;

	base_key = ft_find_nearest_key(number, dict);
	result = 0;
	if (base_key == 0)
	{
		ft_putstr(ft_get_value_of_key(0, dict), 1);
		return ;
	}
	result = number / base_key;
	if (result != 1)
		handle_result_not1(result, base_key, dict);
	if (result == 1)
		handle_result1(base_key, dict);
	if (number % base_key != 0)
	{
		ft_putstr(" ", 1);
		ft_print_number((number % base_key), dict);
	}
	p_space(result, number, base_key, dict);
	return ;
}

void	handle_result1(long long base_key, t_dict dict)
{
	if (base_key >= 100)
	{
		ft_putstr(ft_get_value_of_key(1, dict), 1);
		ft_putstr(" ", 1);
	}
	ft_putstr(ft_get_value_of_key(base_key, dict), 1);
}

void	handle_result_not1(long long result, long long base_key, t_dict dict)
{
	ft_print_number(result, dict);
	ft_putstr(" ", 1);
	ft_putstr(ft_get_value_of_key(base_key, dict), 1);
}

void	p_space(long long res, long long num, long long base_k, t_dict dict)
{
	if ((res != 1 && num % base_k == 0
			&& num % base_k == ft_find_nearest_key(num, dict)))
		ft_putstr(" ", 1);
}

void	ft_print_number_newline(long long number, t_dict dict)
{
	ft_print_number(number, dict);
	ft_putstr("\n", 1);
}
