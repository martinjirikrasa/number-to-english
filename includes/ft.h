/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppfiel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:55:52 by ppfiel            #+#    #+#             */
/*   Updated: 2023/07/22 12:55:52 by ppfiel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dict_entry {
	long long	key;
	char		*value;
}	t_dict_entry;

typedef t_dict_entry	*t_dict;

t_dict			ft_get_dict_from_file(char *filename);
void			ft_generate_dict(t_dict dict, char *filename);
int				ft_update_dict(t_dict base_dict, t_dict ref_dict);
int				ft_is_valid_dict_entry(char *row_string);
char			*ft_get_value_of_key(long long key, t_dict dict);
void			ft_putstr(char *str, int channel);
int				ft_str_len(char *str);
int				ft_str_contains_char(char *str, char c);
char			*ft_str_trim(char *str);
long long		ft_atoi(char *str);
void			ft_print_number(long long number, t_dict dict);
long long		ft_find_nearest_key(long long number, t_dict dict);
void			ft_str_cpy(char *dest, char *src, long long offset, int amount);
char			**ft_key_value_split(char *str);
int				ft_str_len_offset(char *str, int offset);
void			free_dict(t_dict dict);
void			free_entries(t_dict dict, long long amount);
void			free_parts(char **parts);
void			*fill_dict(t_dict *dict, char *buffer, long long amount);
int				get_line_length(char *str, long long offset);
void			ft_str_cat(char *dest, char *src, long long offset, int amount);
int				ft_str_to_entry(char *str, t_dict_entry *entry);
void			add_terminating_dict_entry(t_dict dict, long long index);
int				is_key_contained(t_dict dict, long long size, long long key);
void			ft_str_cat(char *dest, char *src, long long offset, int amount);
int				read_file_buffered(char *filename, char *result);
void			*free_and_null(t_dict dict, long long amt, char *l, char *v);
long long		get_file_size(char *filename);
int				get_line_length(char *str, long long offset);
void			free_all_dicts(t_dict base_dict, t_dict extra_dict);
void			ft_print_number_newline(long long number, t_dict dict);

#endif