/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrino <asobrino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:58:58 by asobrino          #+#    #+#             */
/*   Updated: 2025/04/10 20:27:01 by asobrino         ###   ########.fr       */
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

	print_divisor_title("ft_memcpy");
	ft_memcpy(destino, origen, 10);
	printf("Texto copiado: %s\n", destino);
}
bool	ft_memmove_compare_results(const char *label, const char *std_buf,
		const char *my_buf, size_t size)
{
	if (memcmp(std_buf, my_buf, size) == 0)
	{
		printf("[OK] %s: Resultado coincide con memmove\n", label);
		return (true);
	}
	else
	{
		printf("[FALLO] %s: Resultado DIFERENTE a memmove\n", label);
		printf("memmove:   \"%.*s\"\n", (int)size, std_buf);
		printf("ft_memmove: \"%.*s\"\n", (int)size, my_buf);
		return (false);
	}
}

bool	ft_memmove_test(void)
{
	const size_t	buf_size = 100;
	char			std_buf[buf_size], my_buf[buf_size];
	bool			all_ok;

	print_divisor_title("ft_memmove");
	all_ok = true;
	strcpy(std_buf, "1234567890");
	strcpy(my_buf, "1234567890");
	memmove(std_buf + 5, std_buf, 5);
	ft_memmove(my_buf + 5, my_buf, 5);
	all_ok &= ft_memmove_compare_results("Copia sin solapamiento", std_buf,
			my_buf, buf_size);
	strcpy(std_buf, "abcdef");
	strcpy(my_buf, "abcdef");
	memmove(std_buf + 2, std_buf, 4);
	ft_memmove(my_buf + 2, my_buf, 4);
	all_ok &= ft_memmove_compare_results("Solapamiento src < dest", std_buf,
			my_buf, buf_size);
	strcpy(std_buf, "abcdef");
	strcpy(my_buf, "abcdef");
	memmove(std_buf, std_buf + 2, 4);
	ft_memmove(my_buf, my_buf + 2, 4);
	all_ok &= ft_memmove_compare_results("Solapamiento src > dest", std_buf,
			my_buf, buf_size);
	strcpy(std_buf, "nochange");
	strcpy(my_buf, "nochange");
	memmove(std_buf + 2, std_buf, 0);
	ft_memmove(my_buf + 2, my_buf, 0);
	all_ok &= ft_memmove_compare_results("Copia de 0 bytes", std_buf, my_buf,
			buf_size);
	strcpy(std_buf, "mismo lugar");
	strcpy(my_buf, "mismo lugar");
	memmove(std_buf, std_buf, 10);
	ft_memmove(my_buf, my_buf, 10);
	all_ok &= ft_memmove_compare_results("src == dest", std_buf, my_buf,
			buf_size);
	if (all_ok)
	{
		printf("\n✅ Todos los tests de ft_memmove han pasado correctamente.\n");
	}
	else
	{
		printf("\n❌ Algunos tests de ft_memmove han fallado.\n");
	}
	return (all_ok);
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
	ft_memmove_test();
	return (0);
}
