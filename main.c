/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrino <asobrino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:58:58 by asobrino          #+#    #+#             */
/*   Updated: 2025/04/08 12:53:18 by asobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_isalpha_test(void)
{
	char	l_may;
	char	l_min;

	l_may = 'A';
	l_min = 'a';
	printf("------------------------------\n");
	printf("ft_isalpha\n");
	while (l_min <= 'z')
	{
		printf("Mayus: %c - %i | Minuscula: %c - %i\n", l_may,
			ft_isalpha(l_may), l_min, ft_isalpha(l_min));
		l_may++;
		l_min++;
	}
	printf("Un caracter no alfabetico: 3 - %i\n", ft_isalpha('3'));
}

int	main(void)
{
	ft_isalpha_test();
	return (0);
}
