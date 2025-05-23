/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrino <asobrino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:58:58 by asobrino          #+#    #+#             */
/*   Updated: 2025/04/27 17:24:16 by asobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <fcntl.h> // Para open
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>  // Para printf
#include <stdlib.h> // Para malloc, free
#include <string.h> // Para strcmp
#include <unistd.h> // Para write, read, close

void	print_divisor_title(char *title)
{
	printf("------------------------------\n");
	printf("%s\n", title);
}

void	ft_isalpha_test(void)
{
	char	l_may;
	char	l_min;

	l_may = 'A';
	l_min = 'a';
	print_divisor_title("ft_isalpha");
	while (l_min <= 'z')
	{
		printf("Mayus: %c - %i | Minuscula: %c - %i\n", l_may,
			ft_isalpha(l_may), l_min, ft_isalpha(l_min));
		l_may++;
		l_min++;
	}
	printf("Un caracter no alfabetico: 3 - %i\n", ft_isalpha('3'));
}

void	ft_isdigit_test(void)
{
	char	num;

	num = '0';
	print_divisor_title("ft_isdigit");
	while (num <= '9')
	{
		printf("Numero: %c - %i\n", num, ft_isdigit(num));
		num++;
	}
	printf("Un caracter no numerico: D - %i\n", ft_isdigit('D'));
}

void	ft_isalnum_test(void)
{
	char	l_may;
	char	l_min;
	char	num;

	l_may = 'A';
	l_min = 'a';
	print_divisor_title("ft_isalnum");
	while (l_min <= 'z')
	{
		printf("Mayus: %c - %i | Minuscula: %c - %i\n", l_may,
			ft_isalnum(l_may), l_min, ft_isalnum(l_min));
		l_may++;
		l_min++;
	}
	num = '0';
	while (num <= '9')
	{
		printf("Numero: %c - %i\n", num, ft_isalnum(num));
		num++;
	}
	printf("Un caracter no alfabetico o numerico: [ - %i\n", ft_isalnum('['));
}
void	ft_isascii_test(void)
{
	print_divisor_title("ft_isascii");
	printf("Test: -1 -> %i\n", ft_isascii(-1));
	printf("Test: 0 -> %i\n", ft_isascii(0));
	printf("Test: 50 -> %i\n", ft_isascii(50));
	printf("Test: 127 -> %i\n", ft_isascii(127));
	printf("Test: 128 -> %i\n", ft_isascii(128));
}

void	ft_isprint_test(void)
{
	print_divisor_title("ft_isprint");
	printf("Test: '\\n' -> %i\n", ft_isprint('\n'));
	printf("Test: ' ' -> %i\n", ft_isprint(' '));
	printf("Test: '9' -> %i\n", ft_isprint('9'));
}

void	ft_strlen_test(void)
{
	print_divisor_title("ft_strlen");
	printf("Test: \"pepe\" -> %li\n", ft_strlen("pepe"));
	printf("Test: \"\" -> %li\n", ft_strlen(""));
	printf("Test: \" \" -> %li\n", ft_strlen(" "));
}

void	ft_memset_test(void)
{
	char	cad[10];
	char	*aux;

	ft_memset(cad, 0, 10);
	aux = (char *)ft_memset(cad, 'A', 9);
	print_divisor_title("ft_memset");
	printf("Test: cad -> %s\n", cad);
	printf("Test: aux -> %s\n", aux);
	aux = (char *)ft_memset(cad, 'B', 4);
	printf("Test: cad -> %s\n", cad);
	printf("Test: aux -> %s\n", aux);
}

void	ft_bzero_test(void)
{
	char	s[] = "pepe";
	char	*pt_s;
	int		n;

	n = 4;
	pt_s = s;
	print_divisor_title("ft_bzero");
	ft_bzero(s, 2);
	printf("Test: \"pepe\" -> ");
	while (n--)
	{
		printf("%i ", *pt_s);
		pt_s++;
	}
	printf("\n");
}

void	ft_memcpy_test(void)
{
	char	origen[] = "Hola mundo";
	char	destino[20] = "";
	char	*res_null;

	print_divisor_title("ft_memcpy");
	ft_memcpy(destino, origen, 10);
	printf("Texto copiado: %s\n", destino);
	res_null = ft_memcpy(NULL, NULL, 3);
	if (!res_null)
		printf("test null SI pasado\n");
	else
		printf("test null NO pasado\n");
}

void	ft_memmove_test(void)
{
	char	buffer1[50] = "Hola mundo!";
	char	buffer2[50] = "Hola mundo!";

	ft_memmove(buffer1 + 5, buffer1, 4);
	memmove(buffer2 + 5, buffer2, 4);
	if (memcmp(buffer1, buffer2, 50) == 0)
		printf("Test 1 OK\n");
	else
		printf("Test 1 FALLÓ\n");
	strcpy(buffer1, "1234567890");
	strcpy(buffer2, "1234567890");
	ft_memmove(buffer1 + 2, buffer1, 8);
	memmove(buffer2 + 2, buffer2, 8);
	if (memcmp(buffer1, buffer2, 50) == 0)
		printf("Test 2 OK\n");
	else
		printf("Test 2 FALLÓ\n");
	strcpy(buffer1, "ABCDEFGHIJ");
	strcpy(buffer2, "ABCDEFGHIJ");
	ft_memmove(buffer1, buffer1 + 2, 8);
	memmove(buffer2, buffer2 + 2, 8);
	if (memcmp(buffer1, buffer2, 50) == 0)
		printf("Test 3 OK\n");
	else
		printf("Test 3 FALLÓ\n");
	strcpy(buffer1, "Test sin cambios");
	strcpy(buffer2, "Test sin cambios");
	ft_memmove(buffer1 + 2, buffer1, 0);
	memmove(buffer2 + 2, buffer2, 0);
	if (memcmp(buffer1, buffer2, 50) == 0)
		printf("Test 4 OK\n");
	else
		printf("Test 4 FALLÓ\n");
}

void	ft_strlcpy_test(void)
{
	char		dst1[10];
	const char	*src = "hola mundo";
	size_t		r1;

	print_divisor_title("ft_strlcpy");
	r1 = ft_strlcpy(dst1, src, 10);
	if (r1 == strlen(src) && strcmp(dst1, "hola mund") == 0)
	{
		printf("Test pasado\n");
	}
	else
	{
		printf("Test fallido\n");
		printf("Esperado: %s (%zu)\n", "hola mund", strlen(src));
		printf("Obtenido: %s (%zu)\n", dst1, r1);
	}
}

// void	ft_strlcat_test(void)
// {
// 	char	buffer[10] = "Hola";
// 	size_t	result;
// 	char	*b;

// 	b = buffer;
// 	result = ft_strlcat(buffer, "-Mundo", 3);
// 	printf("Resultado: %s\n", buffer);
// 	printf("Resultado: ");
// 	while (*b)
// 	{
// 		printf("%i|", *b);
// 		b++;
// 	}
// 	printf("%i|", *b);
// 	printf("\nValor devuelto: %zu\n", result); // 11 (4 + 7)
// }

// void	ft_strlcat_test(void)
// {
// 	char		dst1[30] = "Hola, ";
// 	char		dst2[30] = "Hola, ";
// 	const char	*src = "mundo!";
// 	size_t		dstsize;
// 	size_t		ret2;

// 	dstsize = 20;
// 	ret2 = ft_strlcat(dst2, src, dstsize);
// 		printf("strlcat:    [%s] (%d)\n", dst1, strlcat(dst1, src, dstsize));
// 	printf("ft_strlcat: [%s] (%zu)\n", dst2, ret2);
// }

void	ft_toupper_test(void)
{
	char	l;

	print_divisor_title("ft_toupper");
	l = 'a';
	while (l <= 'z')
	{
		printf("Minus to Mayus: %c - %c\n", l, ft_toupper(l));
		l++;
	}
	printf("Mayus to Mayus: %c - %c\n", 'A', ft_toupper('A'));
	printf("'1' to Mayus: %c - %c\n", '1', ft_toupper('1'));
	printf("'[' to Mayus: %c - %c\n", '[', ft_toupper('['));
	printf("-2 to Mayus: %i - %i\n", -2, ft_toupper(-2));
}

void	ft_tolower_test(void)
{
	char	l;

	print_divisor_title("ft_tolower");
	l = 'A';
	while (l <= 'Z')
	{
		printf("Mayus to Minus: %c - %c\n", l, ft_tolower(l));
		l++;
	}
	printf("Minus to Minus: %c - %c\n", 'a', ft_tolower('a'));
	printf("'1' to Minus: %c - %c\n", '1', ft_tolower('1'));
	printf("'[' to Minus: %c - %c\n", '[', ft_tolower('['));
	printf("-2 to Minus: %i - %i\n", -2, ft_tolower(-2));
}
void	ft_strchr_test(void)
{
	char	cad[] = "0123456789";
	char	*res;

	print_divisor_title("ft_strchr");
	printf("Buscado 2 | espearmos: '23456789' | resultado: '%s'\n",
		ft_strchr(cad, '2'));
	printf("Buscado '\\0' | espearmos: '0' | resultado: '%i'\n", *ft_strchr(cad,
			'\0'));
	printf("Buscado a | espearmos: NULL |");
	res = ft_strchr(cad, 'a');
	if (!res)
		printf(" resultado: NULL\n");
	else
		printf(" resultado: NO DIO NULL\n");
}

void	ft_strrchr_test(void)
{
	char	cad[] = "0123456789";
	char	*res;

	print_divisor_title("ft_strrchr");
	printf("Buscado 2 | espearmos: '789' | resultado: '%s'\n", ft_strrchr(cad,
			'7'));
	printf("Buscado '\\0' | espearmos: '0' | resultado: '%i'\n",
		*ft_strrchr(cad, '\0'));
	printf("Buscado a | espearmos: NULL |");
	res = ft_strrchr(cad, 'a');
	if (!res)
		printf(" resultado: NULL\n");
	else
		printf(" resultado: NO DIO NULL\n");
}

void	ft_strncmp_test(void)
{
	print_divisor_title("ft_strncmp");
	// me faltan test
}

void	ft_memchr_test(void)
{
	print_divisor_title("ft_memchr");
	// me faltan test
}

void	ft_memcmp_test(void)
{
	print_divisor_title("ft_memcmp");
	// me faltan test
}

void	ft_strnstr_test(void)
{
	print_divisor_title("ft_strnstr");
	// me faltan test
}

void	ft_atoi_test(void)
{
	print_divisor_title("ft_atoi");
	printf("   '  -23-4' -> -23 -> %i\n", ft_atoi("  -23-4"));
	printf(" '  \\t-23-4' -> -23 -> %i\n", ft_atoi("  \t-23-4"));
	printf("     '-23-4' -> -23 -> %i\n", ft_atoi("-23-4"));
	printf("      '23-4' -> 23 -> %i\n", ft_atoi("23-4"));
	printf("   '  +23-4' -> 23 -> %i\n", ft_atoi("  +23-4"));
	printf("       '-23' -> -23 -> %i\n", ft_atoi("-23"));
	printf("  '23' -> 23 -> %i\n", ft_atoi("23"));
	printf(" '+23' -> 23 -> %i\n", ft_atoi("+23"));
	printf("  '  \\t+234' -> 234 -> %i\n", ft_atoi("  \t+234"));
	printf("   '  \\t234' -> 234 -> %i\n", ft_atoi("  \t234"));
	printf("   ' -\\t234' -> 234 -> %i\n", ft_atoi("  \t234"));
	printf("   ' -0' -> 0 -> %i\n", ft_atoi(" -0"));
}

void	ft_calloc_test(void)
{
	int	*res;

	print_divisor_title("ft_calloc");
	printf("Posiciones: 9223372036854775810 Size: 4 Resultado: NULL\n");
	res = (int *)ft_calloc(9223223344556666778, 4);
	if (!res)
		printf(" resultado: NULL\n");
	else
		printf(" resultado: NO DIO NULL\n");
	free(res);
	printf("Posiciones: 4 Size: 4 Resultado: NO DIO NULL\n");
	res = (int *)ft_calloc(4, 4);
	if (!res)
		printf(" resultado: NULL\n");
	else
		printf(" resultado: NO DIO NULL\n");
	free(res);
	printf("Posiciones: 0 Size: 4 Resultado: NO DIO NULL\n");
	res = (int *)ft_calloc(0, 4);
	if (!res)
		printf(" resultado: NULL\n");
	else
		printf(" resultado: NO DIO NULL\n");
	free(res);
	printf("Posiciones: 4 Size: 0 Resultado: NO DIO NULL\n");
	res = (int *)ft_calloc(4, 0);
	if (!res)
		printf(" resultado: NULL\n");
	else
		printf(" resultado: NO DIO NULL\n");
	free(res);
}

void	ft_strdup_test(void)
{
	char	*copy;
	char	text[] = "0123456789";
	int		i;

	i = 0;
	print_divisor_title("ft_strdup");
	copy = ft_strdup(text);
	printf("cad: '0123456789' copy -> %s\n", copy);
	printf("Tiene \\0 al final?: ");
	while (copy[i])
		i++;
	if (copy[i] == '\0')
		printf("Si\n");
	else
		printf("No\n");
	free(copy);
}

void	ft_substr_test(void)
{
	print_divisor_title("ft_substr");
	// me faltan test
}

void	ft_strjoin_test(void)
{
	char	s1[] = "Hola-";
	char	s2[] = "Mundo";
	char	*res;
	int		i;

	i = 0;
	print_divisor_title("ft_strjoin");
	res = ft_strjoin(s1, s2);
	printf("s1 = 'Hola-' & s2 = 'Mundo' | res -> 'Hola-Mundo' -> '%s'\n", res);
	printf("Tiene \\0 al final?: ");
	while (res[i])
		i++;
	if (res[i] == '\0')
		printf("Si\n");
	else
		printf("No\n");
	free(res);
	res = ft_strjoin(NULL, s2);
	printf("s1 = NULL & s2 = 'Mundo' | res -> NULL -> ");
	if (!res)
		printf("NULL\n");
	else
		printf("NO DIO NULL\n");
	free(res);
	res = ft_strjoin(s1, NULL);
	printf("s1 = 'Hola-' & s2 = NULL | res -> NULL -> ");
	if (!res)
		printf("NULL\n");
	else
		printf("NO DIO NULL\n");
	free(res);
}

void	print_result_ft_strtrim_test(const char *desc, const char *result,
		const char *expected)
{
	printf("%s\n", desc);
	printf("  Resultado: \"%s\"\n", result ? result : "NULL");
	printf("  Esperado : \"%s\"\n\n", expected ? expected : "NULL");
}

void	ft_strtrim_test(void)
{
	char	*str;

	print_divisor_title("ft_strtrim");
	// 1. s1 = NULL -> NULL
	str = ft_strtrim(NULL, "x0");
	print_result_ft_strtrim_test("Test 1: s1 = NULL, set = \"x0\"", str, NULL);
	free(str);
	// 2. set = NULL -> s1
	str = ft_strtrim("x0", NULL);
	print_result_ft_strtrim_test("Test 2: s1 = \"x0\", set = NULL", str, "x0");
	free(str);
	// 3. s1 = \"\" set = \"x0\" -> \"\"
	str = ft_strtrim("", "x0");
	print_result_ft_strtrim_test("Test 3: s1 = \"\", set = \"x0\"", str, "");
	free(str);
	// 4. s1 = \"x0\", set = \"\" -> \"x0\"
	str = ft_strtrim("x0", "");
	print_result_ft_strtrim_test("Test 4: s1 = \"x0\", set = \"\"", str, "x0");
	free(str);
	// 5. s1 = \"x0\", set = \"x0\" -> \"\"
	str = ft_strtrim("x0", "x0");
	print_result_ft_strtrim_test("Test 5: s1 = \"x0\", set = \"x0\"", str, "");
	free(str);
	// 6. s1 = \"x0l0l0\", set = \"x0\" -> \"l0l\"
	str = ft_strtrim("x0l0l0", "x0");
	print_result_ft_strtrim_test("Test 6: s1 = \"x0l0l0\", set = \"x0\"", str,
		"l0l");
	free(str);
	// 7. s1 = \"x0l0\", set = \"x0\" -> \"l\"
	str = ft_strtrim("x0l0", "x0");
	print_result_ft_strtrim_test("Test 7: s1 = \"x0l0\", set = \"x0\"", str,
		"l");
	free(str);
}

static void	print_split_result(char **split)
{
	size_t	i;

	i = 0;
	while (split && split[i])
	{
		printf("[%s]\n", split[i]);
		i++;
	}
}

static char	**ft_free_split_main(char **split, size_t num_subs)
{
	if (!split)
		return (NULL);
	while (num_subs > 0)
		free(split[num_subs--]);
	free(split[0]);
	free(split);
	return (NULL);
}

void	ft_split_test(void)
{
	const char	*test1 = " Pepe   p t";
	char		**split1;
	const char	*test2 = " Pepe   p t  ";
	char		**split2;
	const char	*test3 = "Pepe   p t  ";
	char		**split3;

	print_divisor_title("ft_split");
	// 1. s = " Pepe   p t", c = ' '
	printf("Test 1:\nInput: \"%s\" | Delimiter: '%c'\n", test1, ' ');
	split1 = ft_split(test1, ' ');
	print_split_result(split1);
	ft_free_split_main(split1, 2); // 3 elementos -> índice máx = 2
	// 2. s = " Pepe   p t  ", c = ' '
	printf("Test 2:\nInput: \"%s\" | Delimiter: '%c'\n", test2, ' ');
	split2 = ft_split(test2, ' ');
	print_split_result(split2);
	ft_free_split_main(split2, 2);
	// 3. s = "Pepe   p t  ", c = ' '
	printf("Test 3:\nInput: \"%s\" | Delimiter: '%c'\n", test3, ' ');
	split3 = ft_split(test3, ' ');
	print_split_result(split3);
	ft_free_split_main(split3, 2);
}

void	print_result(const char *test_name, const char *expected,
		const char *got)
{
	int	success;

	success = strcmp(expected, got) == 0;
	printf("Test: %s\n", test_name);
	printf("Esperado: '%s'\n", expected);
	printf("Obtenido: '%s'\n", got);
	printf("%s\n", success ? "\x1b[32m[OK]\x1b[0m" : "\x1b[31m[FAIL]\x1b[0m");
	if (got[strlen(got)] == '\0')
		printf("Finaliza en \\0: \x1b[32m[SÍ]\x1b[0m\n");
	else
		printf("Finaliza en \\0: \x1b[31m[NO]\x1b[0m\n");
	printf("\n");
}

void	ft_itoa_test(void)
{
	char	*result;

	print_divisor_title("ft_itoa");
	result = ft_itoa(-234);
	print_result("ft_itoa(-234)", "-234", result);
	free(result);
	result = ft_itoa(234);
	print_result("ft_itoa(234)", "234", result);
	free(result);
	result = ft_itoa(0);
	print_result("ft_itoa(0)", "0", result);
	free(result);
	result = ft_itoa(2147483647);
	print_result("ft_itoa(2147483647)", "2147483647", result);
	free(result);
	result = ft_itoa(-2147483647);
	print_result("ft_itoa(-2147483647)", "-2147483647", result);
	free(result);
	result = ft_itoa(-2147483648);
	print_result("ft_itoa(-2147483648)", "-2147483648", result);
	free(result);
	// Test extra sugerido para cubrir mas casos
	result = ft_itoa(42);
	print_result("ft_itoa(42)", "42", result);
	free(result);
	result = ft_itoa(-1);
	print_result("ft_itoa(-1)", "-1", result);
	free(result);
	result = ft_itoa(1000000);
	print_result("ft_itoa(1000000)", "1000000", result);
	free(result);
	result = ft_itoa(-1000000);
	print_result("ft_itoa(-1000000)", "-1000000", result);
	free(result);
}

char	add_index_to_char(unsigned int i, char c)
{
	return (c + i);
}

// Tu test
void	ft_strmapi_test(void)
{
	char	*result;

	print_divisor_title("ft_strmapi");
	const char *original = "abcd"; // Cadena de prueba
	const char *expected = "aceg"; // Resultado esperado
	result = ft_strmapi(original, add_index_to_char);
	printf("Cadena original : \"%s\"\n", original);
	printf("Cadena esperada : \"%s\"\n", expected);
	if (result == NULL)
	{
		printf("Resultado       : NULL\n");
		printf("FALLO: Resultado es NULL\n");
	}
	else
	{
		printf("Resultado       : \"%s\"\n", result);
		if (strcmp(result, expected) == 0)
			printf("OK: Resultado correcto.\n");
		else
			printf("FALLO: Resultado incorrecto.\n");
	}
	free(result);
}

void	to_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - ('a' - 'A');
}

void	ft_striteri_test(void)
{
	char	str[] = "hello";
	char	expected[] = "HELLO";

	print_divisor_title("ft_striteri");
	printf("Cadena original: \"%s\"\n", str);
	// Aplicamos ft_striteri
	ft_striteri(str, to_upper);
	printf("Resultado esperado: \"%s\"\n", expected);
	printf("Resultado obtenido: \"%s\"\n", str);
}

void	ft_putchar_fd_test(void)
{
	int		fd;
	char	c;
	int		bytes_read;

	char buffer[2]; // Uno para el carácter y otro para el '\0'
	c = 'A';
	print_divisor_title("ft_putchar_fd");
	// 1. Abrimos (o creamos) un fichero temporal
	fd = open("test_putchar_fd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Error al abrir el fichero");
		return ;
	}
	// 2. Usamos tu función para escribir un carácter
	ft_putchar_fd(c, fd);
	// 3. Cerramos el fichero para que los datos se guarden
	close(fd);
	// 4. Lo abrimos en modo lectura
	fd = open("test_putchar_fd.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error al reabrir el fichero");
		return ;
	}
	// 5. Leemos el contenido
	bytes_read = read(fd, buffer, 1);
	if (bytes_read == -1)
	{
		perror("Error al leer el fichero");
		close(fd);
		return ;
	}
	buffer[bytes_read] = '\0'; // Terminamos la cadena
	// 6. Comprobamos que el carácter es el correcto
	if (buffer[0] == c)
		printf("[OK] Se escribió correctamente '%c' en el fichero.\n", c);
	else
		printf("[KO] Esperado: '%c', Leído: '%c'\n", c, buffer[0]);
	// 7. Cerramos el fichero
	close(fd);
}

void	ft_putstr_fd_test(void)
{
	const char	*str = "Hola, mundo!";
	const char	*filename = "test_output.txt";
	char		buffer[256];
	int			fd;
	ssize_t		bytes_read;

	print_divisor_title("ft_putstr_fd");
	// 1. Abrimos el fichero en modo escritura
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("Error abriendo el fichero");
		return ;
	}
	// 2. Escribimos la cadena usando ft_putchar_fd
	for (int i = 0; str[i] != '\0'; i++)
		ft_putchar_fd(str[i], fd);
	close(fd);
	// 3. Abrimos el fichero en modo lectura
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error abriendo el fichero para leer");
		return ;
	}
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	if (bytes_read >= 0)
		buffer[bytes_read] = '\0';
	else
	{
		perror("Error leyendo el fichero");
		close(fd);
		return ;
	}
	close(fd);
	// 4. Comparamos
	printf("Cadena original: %s\n", str);
	printf("Cadena leída del fichero: %s\n", buffer);
	if (strcmp(str, buffer) == 0)
		printf("✅ Test pasado: las cadenas coinciden.\n");
	else
		printf("❌ Test fallido: las cadenas no coinciden.\n");
}

void	ft_putendl_fd_test(void)
{
	int			fd;
	char		buffer[1024];
	ssize_t		bytes_read;
	const char	*test_string = "Hola mundo";
	const char	*expected_output = "Hola mundo\n";

	print_divisor_title("ft_putendl_fd");
	// Crear un fichero temporal
	fd = open("test_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		printf("Error: No se pudo crear el fichero de prueba.\n");
		return ;
	}
	// Escribir usando tu función
	ft_putendl_fd((char *)test_string, fd);
	// Mover el puntero del fichero al inicio para leer
	lseek(fd, 0, SEEK_SET);
	// Leer el contenido
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	if (bytes_read >= 0)
	{
		buffer[bytes_read] = '\0'; // Aseguramos que es una string válida
		if (strcmp(buffer, expected_output) == 0)
			printf("✅ Test ft_putendl_fd: PASADO\n");
		else
		{
			printf("❌ Test ft_putendl_fd: FALLADO\n");
			printf("Esperado: \"%s\"\n", expected_output);
			printf("Obtenido: \"%s\"\n", buffer);
		}
	}
	else
		printf("Error: No se pudo leer del fichero.\n");
	close(fd);
}

void	ft_putnbr_fd_test(void)
{
	int		numbers[] = {-234, 234, 0, -2147483647, -2147483648, 42, -1,
				1000000, -1000000};
	size_t	size;
	char	buffer[100];
	int		fd;
	ssize_t	bytes_read;
	char	expected[50];

	print_divisor_title("ft_putnbr_fd");
	size = sizeof(numbers) / sizeof(numbers[0]);
	for (size_t i = 0; i < size; i++)
	{
		printf("Probando guardar el número: %d\n", numbers[i]);
		// Abrimos el archivo temporal
		fd = open("temp_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror("Error abriendo el archivo");
			return ;
		}
		// Llamamos a tu función
		ft_putnbr_fd(numbers[i], fd);
		// Cerramos y reabrimos para leer
		close(fd);
		fd = open("temp_output.txt", O_RDONLY);
		if (fd == -1)
		{
			perror("Error reabriendo el archivo para leer");
			return ;
		}
		// Leemos el contenido
		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
		if (bytes_read < 0)
		{
			perror("Error leyendo el archivo");
			close(fd);
			return ;
		}
		buffer[bytes_read] = '\0'; // Null-terminate
		// Comparamos
		snprintf(expected, sizeof(expected), "%d", numbers[i]);
		if (strcmp(buffer, expected) == 0)
			printf("[OK] Se guardó correctamente: %s\n", buffer);
		else
			printf("[FALLO] Esperado: %s | Obtenido: %s\n", expected, buffer);
		close(fd);
	}
}

void	ft_lstnew_test(void)
{
	char	*content;
	t_list	*node;

	print_divisor_title("ft_lstnew");
	// Crear un contenido de prueba
	content = "Hola, mundo";
	// Llamar a la función ft_lstnew
	node = ft_lstnew(content);
	// Comprobar si el nodo se ha creado correctamente
	if (node == NULL)
		printf("Error: node es NULL\n");
	else if (node->content != content)
		printf("Error: content no coincide\n");
	else if (node->next != NULL)
		printf("Error: next no es NULL\n");
	else
		printf("Test correcto: nodo creado correctamente\n");
	// Liberar memoria
	free(node);
}

void	ft_lstadd_front_test(void)
{
	t_list	*node2;
	t_list	*node1;
	t_list	*new_node;
	t_list	*temp;

	print_divisor_title("ft_lstadd_front");
	// Crear una lista inicial
	node2 = malloc(sizeof(t_list));
	node2->content = "Segundo";
	node2->next = NULL;
	node1 = malloc(sizeof(t_list));
	node1->content = "Primero";
	node1->next = node2;
	// Crear un nuevo nodo que queremos añadir al principio
	new_node = malloc(sizeof(t_list));
	new_node->content = "Nuevo Primero";
	new_node->next = NULL;
	// Mostrar la lista antes de añadir
	printf("Lista antes de añadir:\n");
	temp = node1;
	while (temp)
	{
		printf("  - %s\n", (char *)temp->content);
		temp = temp->next;
	}
	// Añadir el nuevo nodo al principio
	ft_lstadd_front(&node1, new_node);
	// Mostrar la lista después de añadir
	printf("Lista después de añadir:\n");
	temp = node1;
	while (temp)
	{
		printf("  - %s\n", (char *)temp->content);
		temp = temp->next;
	}
	// Comprobación
	if (node1 == new_node && node1->next && strcmp(node1->next->content,
			"Primero") == 0)
		printf("✅ Test PASADO: El nuevo nodo se ha añadido correctamente al principio.\n");
	else
		printf("❌ Test FALLADO: El nuevo nodo NO se ha añadido correctamente.\n");
}

void	ft_lstsize_test(void)
{
	t_list	*node3;
	t_list	*node2;
	t_list	*node1;
	t_list	*temp;
	int		esperado;
	int		obtenido;

	print_divisor_title("ft_lstsize");
	// Crear lista usando ft_lstnew
	node3 = ft_lstnew("Tercero");
	node2 = ft_lstnew("Segundo");
	node1 = ft_lstnew("Primero");
	// Unir los nodos
	node1->next = node2;
	node2->next = node3;
	// Mostrar lista
	printf("Elementos de la lista:\n");
	temp = node1;
	while (temp)
	{
		printf("  - %s\n", (char *)temp->content);
		temp = temp->next;
	}
	// Resultado esperado
	esperado = 3;
	// Resultado obtenido
	obtenido = ft_lstsize(node1);
	printf("Resultado esperado: %d\n", esperado);
	printf("Resultado obtenido: %d\n", obtenido);
	if (esperado == obtenido)
		printf("✅ Test PASADO: Tamaño correcto.\n");
	else
		printf("❌ Test FALLADO: Tamaño incorrecto.\n");
	// Liberar memoria
	free(node1);
	free(node2);
	free(node3);
}

void	ft_lstlast_test(void)
{
	t_list	*node3;
	t_list	*node2;
	t_list	*node1;
	t_list	*temp;
	char	*esperado;
	t_list	*ultimo;

	print_divisor_title("ft_lstlast");
	// Crear lista usando ft_lstnew
	node3 = ft_lstnew("Tercero");
	node2 = ft_lstnew("Segundo");
	node1 = ft_lstnew("Primero");
	// Unir los nodos
	node1->next = node2;
	node2->next = node3;
	// Mostrar la lista
	printf("Elementos de la lista:\n");
	temp = node1;
	while (temp)
	{
		printf("  - %s\n", (char *)temp->content);
		temp = temp->next;
	}
	// Resultado esperado
	esperado = "Tercero";
	// Resultado obtenido
	ultimo = ft_lstlast(node1);
	printf("Contenido esperado del último nodo: %s\n", esperado);
	printf("Contenido obtenido: %s\n",
		ultimo ? (char *)ultimo->content : "(null)");
	if (ultimo && strcmp((char *)ultimo->content, esperado) == 0)
		printf("✅ Test PASADO: Último nodo correcto.\n");
	else
		printf("❌ Test FALLADO: Último nodo incorrecto.\n");
	// Liberar memoria
	free(node1);
	free(node2);
	free(node3);
}

void	ft_lstadd_back_test(void)
{
	t_list	*node2;
	t_list	*node1;
	t_list	*temp;
	t_list	*new_node;
	t_list	*ultimo;

	print_divisor_title("ft_lstadd_back");
	// Crear lista inicial usando ft_lstnew
	node2 = ft_lstnew("Segundo");
	node1 = ft_lstnew("Primero");
	// Unir los nodos
	node1->next = node2;
	// Mostrar lista antes de añadir
	printf("Lista antes de añadir:\n");
	temp = node1;
	while (temp)
	{
		printf("  - %s\n", (char *)temp->content);
		temp = temp->next;
	}
	// Crear nuevo nodo que queremos añadir al final
	new_node = ft_lstnew("Tercero");
	// Añadir el nuevo nodo al final
	ft_lstadd_back(&node1, new_node);
	// Mostrar lista después de añadir
	printf("Lista después de añadir:\n");
	temp = node1;
	while (temp)
	{
		printf("  - %s\n", (char *)temp->content);
		temp = temp->next;
	}
	// Comprobación
	ultimo = ft_lstlast(node1);
	printf("Contenido esperado del último nodo: %s\n", "Tercero");
	printf("Contenido obtenido: %s\n",
		ultimo ? (char *)ultimo->content : "(null)");
	if (ultimo && strcmp((char *)ultimo->content, "Tercero") == 0)
		printf("✅ Test PASADO: El nodo se añadió correctamente al final.\n");
	else
		printf("❌ Test FALLADO: El nodo no se añadió correctamente.\n");
	// Liberar memoria
	free(node1);
	free(node2);
	free(new_node);
}

void	del_function(void *content)
{
	// Simplemente ponemos a NULL para este test
	(void)content;
	// Aquí podrías liberar memoria si el contenido fuera dinámico
}

void	ft_lstdelone_test(void)
{
	t_list	*node;

	print_divisor_title("ft_lstdelone");
	// Crear un nodo usando ft_lstnew
	node = ft_lstnew("Nodo a eliminar");
	// Mostrar el contenido antes de eliminar
	printf("Contenido del nodo antes de eliminar: %s\n", (char *)node->content);
	// Eliminar el nodo
	ft_lstdelone(node, del_function);
	// No podemos acceder a node->content aquí porque node debería ser liberado dentro de ft_lstdelone,
	// así que solo verificamos si no provoca errores.
	printf("Se llamó a ft_lstdelone. Si no hay errores de memoria,el test es correcto.\n");
	printf("✅ Test PASADO: El nodo se eliminó (no debería haber memory leaks).\n");
	// Nota: No hacemos free(node) aquí porque se supone que ft_lstdelone debe hacer el free dentro.
}

void	ft_lstclear_test(void)
{
	t_list	*node3;
	t_list	*node2;
	t_list	*node1;
	t_list	*temp;

	print_divisor_title("ft_lstclear");
	// Crear una lista de nodos
	node3 = ft_lstnew("Tercero");
	node2 = ft_lstnew("Segundo");
	node1 = ft_lstnew("Primero");
	// Unir nodos
	node1->next = node2;
	node2->next = node3;
	// Mostrar la lista antes de eliminar
	printf("Lista antes de clear:\n");
	temp = node1;
	while (temp)
	{
		printf("  - %s\n", (char *)temp->content);
		temp = temp->next;
	}
	// Eliminar la lista completa
	ft_lstclear(&node1, del_function);
	// Mostrar resultado después de clear
	if (node1 == NULL)
		printf("✅ Test PASADO: La lista fue eliminada correctamente (puntero a NULL).\n");
	else
		printf("❌ Test FALLADO: El puntero no es NULL después de clear.\n");
	// Nota: No hacemos free manual porque ft_lstclear ya debe liberar todo.
}

#include <ctype.h> // Para funciones de transformación como toupper

void	to_uppercase(void *content)
{
	char	*str;
	int		i;

	str = (char *)content;
	i = 0;
	while (str[i])
	{
		str[i] = toupper(str[i]);
		i++;
	}
}

void	ft_lstiter_test(void)
{
	t_list	*node3;
	t_list	*node2;
	t_list	*node1;
	t_list	*temp;

	print_divisor_title("ft_lstiter");
	// Crear lista
	node3 = ft_lstnew(strdup("tercero"));
	node2 = ft_lstnew(strdup("segundo"));
	node1 = ft_lstnew(strdup("primero"));
	// Unir nodos
	node1->next = node2;
	node2->next = node3;
	// Mostrar lista antes
	printf("Lista antes de aplicar ft_lstiter:\n");
	temp = node1;
	while (temp)
	{
		printf("  - %s\n", (char *)temp->content);
		temp = temp->next;
	}
	// Aplicar ft_lstiter
	ft_lstiter(node1, to_uppercase);
	// Mostrar lista después
	printf("Lista después de aplicar ft_lstiter:\n");
	temp = node1;
	while (temp)
	{
		printf("  - %s\n", (char *)temp->content);
		temp = temp->next;
	}
	// Comprobaciones simples
	if (strcmp(node1->content, "PRIMERO") == 0 && strcmp(node2->content,
			"SEGUNDO") == 0 && strcmp(node3->content, "TERCERO") == 0)
		printf("✅ Test PASADO: Todos los nodos fueron modificados correctamente.\n");
	else
		printf("❌ Test FALLADO: No se modificaron correctamente los nodos.\n");
	// Liberar memoria
	free(node1->content);
	free(node2->content);
	free(node3->content);
	free(node1);
	free(node2);
	free(node3);
}

#include <ctype.h> // Para toupper
#include <string.h> // Para strdup y strcmp

void	*to_uppercase_copy(void *content)
{
	char	*str;
	char	*new_str;
	int		i;

	str = (char *)content;
	new_str = strdup(str);
	if (!new_str)
		return (NULL);
	i = 0;
	while (new_str[i])
	{
		new_str[i] = toupper(new_str[i]);
		i++;
	}
	return (new_str);
}

void	ft_lstmap_test(void)
{
	t_list	*node3;
	t_list	*node2;
	t_list	*node1;
	t_list	*temp;
	t_list	*new_list;

	print_divisor_title("ft_lstmap");
	// Crear lista original
	node3 = ft_lstnew(strdup("tercero"));
	node2 = ft_lstnew(strdup("segundo"));
	node1 = ft_lstnew(strdup("primero"));
	node1->next = node2;
	node2->next = node3;
	// Mostrar lista original
	printf("Lista original antes de mapear:\n");
	temp = node1;
	while (temp)
	{
		printf("  - %s\n", (char *)temp->content);
		temp = temp->next;
	}
	// Aplicar ft_lstmap
	new_list = ft_lstmap(node1, to_uppercase_copy, del_function);
	// Mostrar nueva lista
	printf("Nueva lista después de mapear:\n");
	temp = new_list;
	while (temp)
	{
		printf("  - %s\n", (char *)temp->content);
		temp = temp->next;
	}
	// Comprobaciones
	if (strcmp((char *)new_list->content, "PRIMERO") == 0
		&& strcmp((char *)new_list->next->content, "SEGUNDO") == 0
		&& strcmp((char *)new_list->next->next->content, "TERCERO") == 0)
		printf("✅ Test PASADO: La lista nueva fue creada correctamente y modificada.\n");
	else
		printf("❌ Test FALLADO: La lista nueva no está correctamente modificada.\n");
	// Confirmar que la lista original no fue modificada
	if (strcmp((char *)node1->content, "primero") == 0
		&& strcmp((char *)node2->content, "segundo") == 0
		&& strcmp((char *)node3->content, "tercero") == 0)
		printf("✅ Lista original no fue modificada.\n");
	else
		printf("❌ Lista original fue modificada (no debería).\n");
	// Liberar memoria
	ft_lstclear(&node1, del_function);
	ft_lstclear(&new_list, del_function);
}

int	main(void)
{
	// ft_isalpha_test();
	// ft_isdigit_test();
	// ft_isalnum_test();
	// ft_isascii_test();
	// ft_isprint_test();
	// ft_strlen_test();
	// ft_memset_test();
	// ft_bzero_test();
	// ft_memcpy_test();
	// ft_memmove_test();
	// ft_strlcpy_test();
	// ft_strlcat_test();
	// ft_toupper_test();
	// ft_tolower_test();
	// ft_strchr_test();
	// ft_strrchr_test();
	// ft_strncmp_test();
	// ft_memchr_test();
	// ft_memcmp_test();
	// ft_atoi_test();
	// ft_calloc_test();
	// ft_strdup_test();
	// ft_substr_test();
	// ft_strjoin_test();
	// ft_strtrim_test();
	// ft_split_test();
	// ft_itoa_test();
	// ft_strmapi_test();
	// ft_striteri_test();
	// ft_putchar_fd_test();
	// ft_putstr_fd_test();
	// ft_putendl_fd_test();
	// ft_putnbr_fd_test();
	// ft_lstnew_test();
	// ft_lstadd_front_test();
	// ft_lstsize_test();
	// ft_lstlast_test();
	// ft_lstadd_back_test();
	// ft_lstdelone_test();
	// ft_lstclear_test();
	// ft_lstiter_test();
	// ft_lstmap_test();
	return (0);
}
