/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrino <asobrino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:58:58 by asobrino          #+#    #+#             */
/*   Updated: 2025/04/15 10:22:21 by asobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	return (0);
}
