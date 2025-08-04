/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro-linux <alvaro-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:18:09 by asobrino          #+#    #+#             */
/*   Updated: 2025/08/04 20:28:48 by alvaro-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copiamos la direccion de memoria src en dst size bytes, que debe ser la dimension de dst, la ultima posicion se reserva para poner '\0' al final.
 *
 * @param[out] dst: Direccion de memoria donde copiaremos src, por el tamaño de dst que es size.
 * @param[in] src: Direccion de memoria que copiaremos en dst, por el tamaño de dst que es size.
 * @param[in] size: es el tamaño de dst, la ultima posicion se reserva para el '\0'.
 *
 * @return len_s es la longitud de src. Si size es 0 o menor que len_s, la cadena fue truncada (no se copió completa en dst). Si size es mayor que len_s, la copia fue completa y no hubo truncamiento.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_s;

	len_s = ft_strlen(src);
	if (size == 0)
		return (len_s);
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len_s);
}
