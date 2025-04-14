# Antes de terminar de subirlo
1. Cambiar NAME a libft.a
2. Eliminar del Makefile: mane.c
3. Eliminar main.c
4. Cambia esto en el Makefile:
	```
	# Regla para crear el programa
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
7. Eliminar pdf
8. Eliminar README.md y hacer un commit y push a origin

# Makefile

Su función principal es automatizar la compilación de programas (especialmente en C/C++), aunque también puede usarse para otros tipos de tareas repetitivas (como tests, limpieza de archivos, despliegues, etc.).

- **Nombre del archivo**: debe ser **Makefile** para que el comado `make` lo detecte.

## Contenido

### Variables

Las varables son nombres, todos en mayusculas, que sirven para asignarles nombres, comando... y poder reutilizarlos.

Algunas comunes son:

- **NAME**: Es el nombre que tendra el archivo compilado, si este erchivo quieres que tenga una extension, `.a`, debes ponersela tambien.

	```
	NAME = libft.a
	```

- **CC**: Es el comando de compilacion, se debe usar `cc`.

	```
	CC = cc
	```

	Es el comando que se usa para [compilar un programa](#compilar-un-programa).

- **CFLAGS**: Es la parte con las flags de compilacción.

	```
	CFLAGS = -Wall -Wextra -Werror
	```
	Se utiliza tanto para la crear los [objetos `.o`](#crear-objetos-o-a-partir-de-c) como para [compilar un programa](#compilar-un-programa).

- **AR**: Es el comando de compilacion final que se usa para crear una [libreria estatica](#compilar-una-libreria-estatica).

	```
	AR = ar rcs
	```

- **SRC**: Lista de archivos `.c` que quieres compilar.

	- Puedes ponerlos en la  misma linea separados por espacios.
		```
		SRC = main.c ft_isalpha.c ft_isdigit.c ...
		```
	- Puedes poner uno por linea, finalizados por un ' \'.
		```
		SRC = main.c \
			ft_isalpha.c \
			ft_isdigit.c \
			...
		```

- **OBJ**: Los `.c` deben ser compilados individualmente a `.o`, par despues ser compilados todos a un solo ejecutable.

	Para poder hacer esto lo que neceitamos es coger toda la lista de **SRC** y passar de `.c` a `.o`.

	```
	OBJ = $(SRC:.c=.o)
	```
- **RM**: Comando para eliminar archivos.

	```
	RM = rm -f
	```

	Se usa en las reglas [clean](#clean) y [fclean](#fclean)

### Reglas

Son las instrucciones que definen cómo deben generarse los archivos de salida a partir de los archivos de entrada.

#### Regla por defecto

```
# Regla por defecto
all: $(NAME)
```

#### Crear objetos .o a partir de .c

```
# Regla para crear los objetos (.o) a partir de los archivos fuente (.c)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
```
#### Compilacion final

- Compilar un programa:

	```
	$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $@ $^
	```

- Compilar una libreria estatica:

	```
	$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)
	```

#### clean

```
# Regla para limpiar los objetos
clean:
	$(RM) $(OBJ)
```

#### fclean
```
# Regla para eliminar todo (librería y objetos)
fclean: clean
	$(RM) $(NAME)
```

#### re (recompilacion o relink)
```
# Regla para recompilar todo
re: fclean all
```

### Plantilla

```
# Variables
NAME = #nombre compilacion
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs  # Comando para crear la librería estática
SRC = # Aquí deberías poner tus archivos fuente
OBJ = $(SRC:.c=.o)
RM = rm -f  # Comando para eliminar archivos

# Regla por defecto
all: $(NAME)

# Regla para crear los objetos (.o) a partir de los archivos fuente (.c)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Reglas de compilacion final
#
# # Regla para crear la librería estática
# $(NAME): $(OBJ)
# 	$(AR) $(NAME) $(OBJ)
#
# # Regla para crear el programa ejecutable
# $(NAME): $(OBJ)
#	$(CC) $(CFLAGS) -o $@ $^

# Regla para limpiar los objetos
clean:
	$(RM) $(OBJ)

# Regla para eliminar todo (librería o ejecutable y objetos)
fclean: clean
	$(RM) $(NAME)

# Regla para recompilar todo
re: fclean all

```

# Conceptos

## Compilación

### Compilar

Los archvos `.o` surgidos de una compilacion de archivos `.c`son su compilacion pero aun no estan [enlazados](#enlazar).

### Enlazar

Después de que el compilador convierte tu código `.c` en archivos `.o` (objetos), [compilar](#compilar), todavía no tienes un programa que puedas ejecutar. Cada `.o` tiene una parte del trabajo hecho, pero están como "incompletos".

**Enlazar** es el proceso de juntar todos esos `.o` (y las bibliotecas necesarias) para crear el ejecutable final, como un `.exe` en Windows o simplemente un binario en Linux/Mac.

## Tipos de compilacion

| Aspecto                  | [Programa en C/C++](#compilar-programa)                | [Librería Estática en C/C++](#compilar-una-libreria-estatica)  |
|--------------------------|--------------------------------------------------------|------------------------------------------------|
| 🎯 Objetivo final         | Crear un archivo ejecutable (`.exe`, `a.out`, etc.)    | Crear un archivo de librería (`.a`, `.lib`)    |
| 📦 Contenido final        | Código + todas las librerías enlazadas                 | Solo código objeto (sin `main`, por ejemplo)    |
| 🔗 Linking                | Se enlaza todo (código y librerías)                    | No se enlaza, solo se agrupan los `.o`         |
| 💾 Tamaño del resultado   | Mayor (incluye todo lo necesario)                      | Menor (solo funciones reutilizables)           |
| 💡 Uso                   | Ejecutar directamente                                  | Reutilizar en otros programas                  |


### Compilar programa

> !Nota
> Para saber el proceso de compilacion mirar: [Compilación](#compilación)

Compilar un programa consiste en tener al final de la compilacion un archivo que el ordenador es capaz de ejecutar por si mismo.

#### Comando compilar programa

Esto se hace con `cc`.

### Compilar una libreria estatica

> !Nota
> Para saber el proceso de compilacion mirar: [Compilación](#compilación)

Una librería estática es un archivo que contiene código objeto precompilado que puedes usar en múltiples programas. Su extensión suele ser:

- `.a` en Linux/macOS

- `.lib` en Windows

No se ejecuta por sí sola, sino que se enlaza dentro del ejecutable final durante la fase de [linkeo](#enlazar).

#### Comando compilar una libreria estatica

Esto se hace con `ar rcs [nane_libreria.a] [todos los .o]`.
