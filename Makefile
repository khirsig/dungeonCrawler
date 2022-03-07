CC = gcc

NAME = dungeon

LIBPATH = ./libft/libft.a
LFLAGS =  -lraylib -O2

OBJDIR = ./objs/
OBJECTS = $(OBJDIR)/*.o

SRC =	srcs/main.c										\
		srcs/initializer/initializer.c					\
		srcs/initializer/init_window.c					\
		srcs/initializer/init_player.c					\
		srcs/initializer/init_console.c					\
		srcs/initializer/init_npc.c						\
		srcs/initializer/init_inventory.c				\
		srcs/initializer/init_gameloop.c				\
		srcs/initializer/init_utils.c					\
		srcs/initializer/init_minimap.c					\
		srcs/gameloop/gameloop.c						\
		srcs/gameloop/loop_mainmenu.c					\
		srcs/gameloop/loop_loadingscreen.c				\
		srcs/gameloop/loop_ingame.c						\
		srcs/gameloop/ingame/ingame_draw.c				\
		srcs/gameloop/ingame/ingame_keyhook.c			\
		srcs/gameloop/ingame/ingame_inventory.c			\
		srcs/gameloop/ingame/ingame_item.c				\
		srcs/gameloop/ingame/ingame_currency.c			\
		srcs/gameloop/ingame/ingame_interface.c			\
		srcs/gameloop/ingame/ingame_console.c			\
		srcs/parser/parser.c							\
		srcs/parser/parser_map.c						\
		srcs/parser/parser_map_length.c					\
		srcs/parser/parser_map_error.c					\

all: $(NAME)

$(NAME): $(OBJECTS)
	make --directory=./libft
	$(CC) $(OBJECTS) $(LFLAGS) -o $(NAME) $(LIBPATH)

$(OBJECTS): $(SRC)
	$(CC) -c $(CFLAGS) $(SRC)
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
