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
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	# main.c \
	# Aquí deberías poner tus archivos fuente
OBJ = $(SRC:.c=.o)
AR = ar rcs  # Comando para crear la librería estática
RM = rm -f  # Comando para eliminar archivos

# Regla por defecto
all: $(NAME)

# Reglas de compilacion final
#
# Regla para crear la librería estática
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
#
# #Regla para crear el programa ejecutable
# $(NAME): $(OBJ)
# 	$(CC) $(CFLAGS) -o $@ $^

# Regla para crear los objetos (.o) a partir de los archivos fuente (.c)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar los objetos
clean:
	$(RM) $(OBJ)

# Regla para eliminar todo (librería y objetos)
fclean: clean
	$(RM) $(NAME)

# Regla para recompilar todo
re: fclean all
