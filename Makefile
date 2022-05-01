SO_LONG = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
INC = -I ./inc
BUILD = build

FILES = get_next_line/get_next_line_utils get_next_line/get_next_line \
	ft_printf/ft_argp ft_printf/ft_hexa ft_printf/ft_printf  ft_printf/ft_putchar \
	ft_printf/ft_putnbr ft_printf/ft_putstr ft_printf/ft_unsignednumber\
	so_long_map_utilis so_long so_long_functions_needs

OBJ = $(addprefix $(BUILD)/, $(FILES:=.o))
all: $(SO_LONG)

$(SO_LONG) : $(OBJ)
	$(CC) $(MLXFLAGS) $(OBJ) -o $(SO_LONG)
	
$(BUILD)/%.o : src/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean :
	rm -rf $(BUILD)
fclean : clean
	rm -rf $(SO_LONG)

re : fclean all

.PHONY : re fclean clean all