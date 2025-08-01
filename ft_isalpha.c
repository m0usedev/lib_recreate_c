/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro-linux <alvaro-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:22:10 by asobrino          #+#    #+#             */
/*   Updated: 2025/08/01 18:42:18 by alvaro-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Determina si un caracter es alfabetico.
 *
 * @param[in] c: Recibe el numero decimal que representa el char, aunque tambien funcionaria con tipo char.
 *
 * @return 1024 en caso de se un caracter alfanumerico y 0 en caso contrario.
 */
int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1024);
	return (0);
}
