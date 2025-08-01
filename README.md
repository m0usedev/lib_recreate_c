# Antes de terminar de subirlo
0. revisar el main y los test
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
# Indice

1. [Makefile](#makefile)
	1. [Contenido](#contenido)
		- [Variables](#variables)
		- [Reglas](#reglas)
			- [Regla por defecto (all)](#regla-por-defecto-all)
			- [Compilación files](#compilación-files)
			- [Crear objetos .o a partir de .c](#crear-objetos-o-a-partir-de-c)
			- [clean](#clean)
			- [fclean](#fclean)
			- [re (recompilación o relink)](#re-recompilacion-o-relink)
		- [Variables automáticas](#variables-automaticas)
		- [Plantilla](#plantilla)
2. [Conceptos](#conceptos)
   - [Compilación](#compilacion)
     - [Compilar](#compilar)
     - [Enlazar](#enlazar)
   - [Tipos de compilación](#tipos-de-compilacion)
     - [Compilar programa](#compilar-programa)
     - [Compilar una librería estática](#compilar-una-libreria-estatica)

# Funciones
## Manipulacion de cadenas
### ft_strlen
Longitud de la cadena.
###
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

#### Regla por defecto (all)

```
# Regla por defecto
all: $(NAME)
```

En un Makefile, `all` es la regla por defecto, es decir, la que se ejecuta si simplemente usas `make` sin argumentos en la terminal.

Esta regla buscara `$(NAME)` y activara [Compilación files](#compilación-files)

#### Compilación files

- Compilar un programa:

	```
	$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $@ $^
	```
	Este comando compila un programa, un ejecutable directamente desde archivos `.o`.

	Los  simbolos que ves son [variables uatomaticas](#variables-automaticas).

	Cuando empiece a jeecutarse buscara los archivos `$(OBJ)` y revisa si esos `.o` existen o si sus fuentes `.c` han cambiado. Si algún `.o` falta o está desactualizado, pasa a la siguiente regla: [Crear objetos .o a partir de .c](#crear-objetos-o-a-partir-de-c). Despues ejecuta el ccomando con los `.o`ya creados.

- Compilar una libreria estatica:

	```
	$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)
	```

	Esta regla construye una librería estática (normalmente un archivo .a) a partir de archivos objeto .o.

	Cuando empiece a jeecutarse buscara los archivos `$(OBJ)` y revisa si esos `.o` existen o si sus fuentes `.c` han cambiado. Si algún `.o` falta o está desactualizado, pasa a la siguiente regla: [Crear objetos .o a partir de .c](#crear-objetos-o-a-partir-de-c). Despues ejecuta el ccomando con los `.o`ya creados.


#### Crear objetos .o a partir de .c

```
# Regla para crear los objetos (.o) a partir de los archivos fuente (.c)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
```

Los  simbolos que ves son [variables uatomaticas](#variables-automaticas).

```
%.o: %.c
```

- `%.o: %.c` → esta es una regla implícita o regla patrón. Le dice a make cómo compilar cualquier archivo .c en un .o correspondiente.

- `%` → es un comodín que representa el mismo nombre base en ambos lados.
Ejemplo: main.c se compilará a main.o.

```
$(CC) $(CFLAGS) -c $< -o $@
```

- `$(CC)` → el compilador, normalmente cc.

- `$(CFLAGS)` → las opciones de compilación, como `-Wall, -Wextra, -Werror`.

- `$<` → la primera dependencia, en este caso el .c.

- `$@` → el objetivo, en este caso el .o.

Los  simbolos que ves son [variables uatomaticas](#variables-automaticas).

#### clean

```
# Regla para limpiar los objetos
clean:
	$(RM) $(OBJ)
```

Invocar este comando junto a make `make clean`lo que hace es ejecutar `rm -f func1.o fun2.o...`. Es para eliminar todos los `.o`.

#### fclean
```
# Regla para eliminar todo (librería y objetos)
fclean: clean
	$(RM) $(NAME)
```

Invocar este comando junto a make `make fclean`lo que hace es ejecutar [clean](#clean) y despues eleimina tu ejecutable `rm -f ejecutable/libreria`.

#### re (recompilacion o relink)
```
# Regla para recompilar todo
re: fclean all
```

Invocar este comando junto a make `make re`lo que hace es ejecutar [fclean](#fclean) y despues [all](#regla-por-defecto-all) para recompilar.

### Variables automaticas

Esots símbolos `$@` y `$^` (y otros como `$<`, `$?`, etc.) son **variables automáticas** que usa `make` dentro de las reglas para que no tengas que repetir nombres de archivos.

Son súper útiles para que tu Makefile sea más limpio, reutilizable y menos propenso a errores.

---

### 🧩 Las variables automáticas más comunes

| Variable | ¿Qué representa? | Ejemplo si tienes esta regla: `mi_programa: main.o utils.o` |
|----------|------------------|-------------------------------------------------------------|
| `$@`     | El nombre del objetivo actual               | `mi_programa`                   |
| `$^`     | Todas las dependencias (prerequisitos)      | `main.o utils.o`                |
| `$<`     | La primera dependencia                      | `main.o`                        |
| `$?`     | Solo las dependencias más nuevas que el objetivo | *(por ejemplo, si solo `utils.o` cambió)* |

---


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
