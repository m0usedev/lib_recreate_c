/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro-linux <alvaro-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:53:18 by asobrino          #+#    #+#             */
/*   Updated: 2025/08/04 20:34:05 by alvaro-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Esta fucnion cantatena size bytes de src en el final de dest, dejando la ultima posicion para '\0'.
 *
 * @param[out] dst: Direccion de memoria en la que se concatenaran size bytes de src.
 * @param[in] src: Direccion de memoria de la que se concatenaran size bytes en dst.
 * @param[in] size: Cantidad de bytes que se concatenaran de src en dst.
 *
 * @return Devuelve la longitud que tendría la cadena final si no se hubiera truncado (strlen(src) + strlen(dst original)), osea se hubiera concatenado todo src en dst.
 * En caso de que el resultado sea src + size es que no se pudo hacer la concatenacion y si no, el resultado sera src + dst, para ver si nuestro resultado tiene la misma longitud y por tanto no se ha producido truncamiento.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l_dst;
	size_t	l_src;
	size_t	count;

	l_dst = ft_strlen(dst);
	l_src = ft_strlen(src);
	if (size <= l_dst)
		return (l_src + size);
	count = l_dst;
	while (*src && count < (size - 1))
	{
		dst[count] = *src++;
		count++;
	}
	dst[count] = '\0';
	return (l_dst + l_src);
}
