SO_LONG = so_long
SO_LONG_B = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
INC = -I ./inc
BUILD = build

FILES = get_next_line/get_next_line_utils get_next_line/get_next_line \
	ft_printf/ft_argp ft_printf/ft_hexa ft_printf/ft_printf  ft_printf/ft_putchar \
	ft_printf/ft_putnbr ft_printf/ft_putstr ft_printf/ft_unsignednumber\
	so_long_map_utilis so_long so_long_functions_needs so_long_movment_utilis so_long_image_utilis
	
B_FILES = get_next_line/get_next_line_utils get_next_line/get_next_line \
	ft_printf/ft_argp ft_printf/ft_hexa ft_printf/ft_printf  ft_printf/ft_putchar \
	ft_printf/ft_putnbr ft_printf/ft_putstr ft_printf/ft_unsignednumber\
	so_long_bonus/so_long_map_utilis_bonus so_long_bonus/so_long_bonus so_long_bonus/so_long_functions_needs_bonus\
	so_long_bonus/so_long_movment_utilis_bonus so_long_bonus/so_long_image_utilis_bonus \
	so_long_bonus/so_long_patrol_bonus so_long_bonus/so_long_functions_bonus

OBJ = $(addprefix $(BUILD)/, $(FILES:=.o))

OBJ_B = $(addprefix $(BUILD)/, $(B_FILES:=.o))

all: $(SO_LONG)

bonus: $(SO_LONG_B)

$(SO_LONG) : $(OBJ)
	$(CC) $(MLXFLAGS) $(OBJ) -o $(SO_LONG)
	
$(SO_LONG_B) : $(OBJ_B)
	$(CC) $(MLXFLAGS) $(OBJ_B) -o $(SO_LONG_B)
	
$(BUILD)/%.o : src/%.c 
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	
clean :
	rm -rf $(BUILD) $(BUILD_B)
fclean : clean
	rm -rf $(SO_LONG) $(SO_LONG_B)

re : fclean all

.PHONY : re fclean clean all