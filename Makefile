CC = gcc

NAME = dungeon

LIBPATH = ./libft/libft.a

LFLAGS = `pkg-config --libs --cflags raylib`
CFLAGS = -Wall -Werror -Wextra

OBJDIR = ./objs/
OBJECTS = $(OBJDIR)/*.o

SRC =	srcs/main.c										\
		srcs/initializer/initializer.c					\
		srcs/initializer/init_window.c					\
		srcs/initializer/init_player.c					\
		srcs/initializer/init_gameloop.c				\
		srcs/gameloop/gameloop.c						\
		srcs/gameloop/loop_mainmenu.c					\
		srcs/gameloop/loop_loadingscreen.c				\
		srcs/gameloop/loop_ingame.c						\
		srcs/gameloop/ingame/ingame_draw.c				\
		srcs/gameloop/ingame/ingame_keyhook.c			\
		srcs/gameloop/ingame/ingame_interface.c			\
		srcs/parser/parser.c							\
		srcs/parser/parser_map.c						\
		srcs/parser/parser_map_length.c					\
		srcs/parser/parser_map_error.c					\

all: $(NAME)

$(NAME): $(OBJECTS)
	@make --directory=./libft
	@$(CC) $(OBJECTS) $(LFLAGS) $(CFLAGS) -o $(NAME) $(LIBPATH)

$(OBJECTS): $(SRC)
	@$(CC) -c $(CFLAGS) $(SRC)
	@rm -rf ./objs; mkdir ./objs
	@mv *.o $(OBJDIR)

clean:
	@make clean --directory=./libft
	@rm -f $(OBJECTS)
	@rm -rf ./objs

fclean: clean
	@make fclean --directory=./libft
	@rm -rf $(NAME)

re: fclean $(NAME)
