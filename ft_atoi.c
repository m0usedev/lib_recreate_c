/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrino <asobrino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 09:48:49 by asobrino          #+#    #+#             */
/*   Updated: 2025/04/17 10:59:14 by asobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * 1. reccorrer todos los espacios de isspace(3)
 * 2. Recorrerr un solo signo '-' o '+'
 * 3. Recorrer todos los numeros hasta un caracter no numerico.
 *

	* Vamos a empezar con una varaible en 0 si al final no hay numero simplemente devolveremos 0.
 */
static int	ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	char	sing_num;
	int		n;

	n = 0;
	sing_num = '+';
	while (ft_isspace(*nptr) == 1)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		sing_num = *nptr;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = n * 10 + (*nptr - '0');
		nptr++;
	}
	if (n != 0 && sing_num == '-')
		n = n * -1;
	return (n);
}
