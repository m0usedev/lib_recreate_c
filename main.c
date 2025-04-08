/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrino <asobrino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:58:58 by asobrino          #+#    #+#             */
/*   Updated: 2025/04/08 13:47:58 by asobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

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

int	main(void)
{
	// ft_isalpha_test();
	// ft_isdigit_test();
	// ft_isalnum_test();
	return (0);
}
