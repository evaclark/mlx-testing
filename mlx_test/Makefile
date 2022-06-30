NAME = tutorial

SOURCES = main.c

OBJECTS = $(SOURCES:.c=.o)

FLAGS = -Wall -Wextra -Werror -c
LINKS = -I main.c -L mlx -l mlx -l ft -framework OpenGL \
	   	-framework Appkit

all: $(NAME)

$(NAME): $(OBJECTS)
    gcc $(SOURCES) -o $(NAME) $(FLAGS) $(LINKS)
