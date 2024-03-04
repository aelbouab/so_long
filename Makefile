NAME = so_long

NAME_B = so_long_b

CC = cc 

FLAGS = -Wall -Wextra -Werror -Imlx

SRC = ft_split.c \
		parssing.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_putstr_fd.c \
		floodfill.c \
		drow_map.c \
		ft_imgnew.c \
		len.c \
		ft_putnbr.c \
		move_p.c \
		exitdoor.c \
		so_long.c

SRC_B = get_next_line.c \
			get_next_line_utils.c \
			ft_split.c \
			ft_putnbr.c \
			ft_itoa.c \
			len.c \
			ft_putstr_fd.c \
			exitdoor.c \
			monster.c \
			animation.c \
			mnstr_move.c \
			parssing_bonus.c\
			floodfill_bonus.c \
			drow_map_bonus.c \
			ft_imgnew_bonus.c \
			move_p_bonus.c \
			so_long_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

INCLUDE = so_long.h

all: $(NAME)

bonus: $(NAME_B)

%.o: %.c $(INCLUDE)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME_B): $(OBJ_B) $(INCLUDE)
	$(CC) $(OBJ_B) -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_B)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_B)

re: fclean all

.PHONY: clean