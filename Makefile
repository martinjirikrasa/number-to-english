# Dirs
SRC_DIR =	./srcs/
INC_DIR =	./includes/

# .c und .o files

SRC_FILES =	main.c \
			ft_str_contains_char.c \
			ft_str_len.c \
			ft_is_valid_dict_entry.c \
			ft_print_number.c \
			ft_putstr.c \
			ft_get_value_of_key.c \
			ft_findNearestKey.c \
			ft_key_value_split.c \
			ft_str_cpy.c \
			ft_str_trim.c \
			ft_get_dict_from_file.c \
			ft_atoi.c \
			ft_update_dict.c \
			ft_free_utils.c \
			ft_fill_dict_from_buffer.c \
			ft_read_file_utils.c

SRCS =		$(addprefix $(SRC_DIR), $(SRC_FILES))
O_FILES =	$(SRCS:.c=.o)

# Compiler settings
CC =		cc
CFLAGS =	-Wall -Wextra -Werror
INC_FLAGS =	-I $(INC_DIR)

# Target
NAME =	rush-02

$(NAME):	$(O_FILES)
				$(CC) $(CFLAGS) $(O_FILES) -o $(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $(INC_FLAGS) $< -o ${<:.c=.o}

clean:
				rm -rf $(O_FILES)

fclean:		clean
				rm -f $(NAME)

.PHONY: 	clean fclean

