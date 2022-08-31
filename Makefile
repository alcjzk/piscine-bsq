NAME = bsq
FILES = main ft_atoi ft_strlen ft_trim_start read map ft_string solve read_map
OBJECTS = $(foreach F,$(FILES),obj/$(F).o)
SRCS = $(foreach F,$(FILES),src/$(F).c)
FLAGS = -Iinc -Wall -Werror -Wextra 

OBJ = obj
SRC = src

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS)
	gcc $(FLAGS) -o $(NAME) $(OBJECTS)

$(OBJ)/%.o: $(SRC)/%.c
	-@mkdir $(OBJ)
	gcc $(FLAGS) -c -o $@ $^

.PHONY: clean
clean:
	rm -rf $(OBJ)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all