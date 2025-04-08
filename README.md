# Antes de terminar de subirlo
1. Cambiar NAME a libft.a
2. Eliminar del Makefile: mane.c
3. Eliminar main.c
4. Cambia esto en el Makefile:
	```
	# Regla para crear la librería estática
	$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $@ $^
	```
	Por esto:
	```
	# Regla para crear la librería estática
	$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)
	```
5. Eliminar todos los ejecutables, .o y .a
6. Eliminar .gitignore
4. Eliminar README.md y hacer un commit y push a origin
