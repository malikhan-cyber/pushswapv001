NAME = pushswap.a
FLAGS = -Werror -Wall -Wextra
BIN = ./bin/
CC = cc
SRCS = main.c push.c reverse_rotate.c rotate.c stack.c swap.c simple_sorting.c medium_sorting.c complex_sorting.c adaptive_sorting.c position_utils.c parsing.c list_contents.c list_utils.c
OBJS = $(SRCS:%.c=$(BIN)%.o)
LIB = $(BIN)libft.a
LIBDIR = /

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	$(CC) $(OBJS) $(LIB) $(FLAGS) -o $(NAME)

$(BIN)%.o: %.c
	mkdir -p $(BIN)
	$(CC) -c $(FLAGS) -g -o $@ $<

.PHONY: all fclean clean re clean/%.a fclean/%.a

$(LIB): $(shell find $(basename $(notdir $(LIB))) -name '*.c' -or -name '*.h' -or -name 'Makefile')
	make -C $(basename $(notdir $(LIB)))
	cp $(basename $(notdir $(LIB)))/$(notdir $@) $@

re: fclean all

clean:
	rm $(BIN) -rf
	make -C $(basename $(notdir $(LIB))) fclean

fclean: clean
	rm $(name) -f
