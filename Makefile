# Variables
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	#main.c \
	# Aquí deberías poner tus archivos fuente
OBJ = $(SRC:.c=.o)
AR = ar rcs  # Comando para crear la librería estática
RM = rm -f  # Comando para eliminar archivos

# Regla por defecto
all: $(NAME)

# Regla para crear la librería estática
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# Regla para limpiar los objetos
clean:
	$(RM) $(OBJ)

# Regla para eliminar todo (librería y objetos)
fclean: clean
	$(RM) $(NAME)

# Regla para recompilar todo
re: fclean all

# Regla para crear los objetos (.o) a partir de los archivos fuente (.c)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
