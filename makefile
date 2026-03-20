# Nazwa Twojej biblioteki z rozszerzeniem .dll
NAME = libdsa.dll

# Kompilator
CC = gcc
# Flaga -fPIC jest ważna dla kodu współdzielonego (Position Independent Code)
CFLAGS = -Wall -Wextra -O2 -fPIC

SRCS = dsa.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

# Tworzenie pliku .dll
$(NAME): $(OBJS)
	$(CC) -shared -o $(NAME) $(OBJS) -Wl,--out-implib,lib$(NAME).a
	@echo "Biblioteka DLL została utworzona!"

# Kompilacja plików .c do .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) lib$(NAME).a

re: fclean all

.PHONY: all clean fclean re