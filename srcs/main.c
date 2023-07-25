/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrasa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:21:45 by mkrasa            #+#    #+#             */
/*   Updated: 2023/07/23 14:21:47 by mkrasa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	extra_dic_check(t_dict extra_dict, t_dict base_dict)
{
	if (extra_dict == NULL)
	{
		ft_putstr("Dict Error\n", 2);
		free_dict(base_dict);
		return (0);
	}
	return (1);
}

int	is_valid_check(int is_valid, t_dict base_dict, t_dict extra_dict)
{
	if (!is_valid)
	{
		ft_putstr("Dict Error\n", 2);
		free_dict(base_dict);
		free_dict(extra_dict);
		return (0);
	}
	return (1);
}

void	case1_normal(char *number)
{
	long long	num;
	t_dict		dict;

	num = ft_atoi(number);
	if (num == -1)
	{
		ft_putstr("Error\n", 2);
		return ;
	}
	dict = ft_get_dict_from_file("./assets/numbers.dict");
	if (dict == NULL)
	{
		ft_putstr("Dict Error\n", 2);
		return ;
	}
	ft_print_number_newline(num, dict);
	free_dict(dict);
	return ;
}

void	case2_ref_dic(char *number, char *filename)
{
	long long	num;
	t_dict		base_dict;
	t_dict		extra_dict;
	int			is_valid;

	num = ft_atoi(number);
	if (num == -1)
	{
		ft_putstr("Error\n", 2);
		return ;
	}
	base_dict = ft_get_dict_from_file("./assets/numbers.dict");
	if (base_dict == NULL)
	{
		ft_putstr("Dict Error\n", 2);
		return ;
	}
	extra_dict = ft_get_dict_from_file(filename);
	if (!extra_dic_check(extra_dict, base_dict))
		return ;
	is_valid = ft_update_dict(base_dict, extra_dict);
	if (!is_valid_check(is_valid, base_dict, extra_dict))
		return ;
	ft_print_number_newline(num, base_dict);
	free_all_dicts(base_dict, extra_dict);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (argv[1][0] < '0' && argv[1][0] != '+')
		{
			ft_putstr("Error\n", 2);
			return (0);
		}
		case1_normal(argv[1]);
	}
	else if (argc == 3)
	{
		if (argv[2][0] < '0' && argv[2][0] != '+')
		{
			ft_putstr("Error\n", 2);
			return (0);
		}
		case2_ref_dic(argv[2], argv[1]);
	}
	else
	{
		ft_putstr("Incorrect number of arguments entered.\n", 2);
		return (0);
	}
}
