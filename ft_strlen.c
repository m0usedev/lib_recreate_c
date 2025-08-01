/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro-linux <alvaro-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:05:33 by asobrino          #+#    #+#             */
/*   Updated: 2025/08/01 18:28:43 by alvaro-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Devuelve la longitud de una cadena.
 *
 * @param[in] s: Se le pasa el puntero de una cadena, como constante para no poder modificarla en el interior de la funcion.
 * @return size_t: Es un tipo especial que se usa para representar tamaños, que garantiza que podra reprensentar cualquier tamaño posible en tu sistema, de la librería <stddef.h>.
 */
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
